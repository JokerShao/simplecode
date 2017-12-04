#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <signal.h>

#include "../../client/protocol.h"

static int loginhandler(const struct login_st *rcv);
int main(void)
{
    sqlite3 *db = NULL;
    int ret;
    char *errmsg;
    const char *sql;
    int sd;
    struct sockaddr_in laddr, raddr;
    socklen_t raddrlen;
    struct login_st rcvbuf;
    pid_t pid;
    struct sigaction act;


    //使得子进程不变成僵尸进程
    act.sa_handler = SIG_IGN;
    act.sa_flags = SA_NOCLDWAIT;
    sigaction(SIGCHLD, &act, NULL);


    //创建数据库---》并创建注册表(count, passwd)
    ret = sqlite3_open("../netchat.sqlite3", &db);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "sqlite3_open() failed\n");
        exit(1);
    }
    sql = "create table if not exists loginTable(no integer primary key autoincrement not null, \
           count text not null)";
    ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "sqlite3_exec():%s\n", errmsg);
        goto ERROR1;
    }
    sqlite3_close(db);

    //初始化与客户端通信的报式套接字
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sd < 0) {
        perror("socket()");
        goto ERROR2;
    }

    laddr.sin_family = AF_INET;//ipv4
    laddr.sin_port = htons(LOGIN_SERVER_PORT);
    inet_aton(LOGIN_SERVER_IP, &laddr.sin_addr);
    if (bind(sd, (void *)&laddr, sizeof(laddr)) < 0) {
        perror("bind()");//errno
        goto ERROR3;
    }

    //收发数据包
    raddrlen = sizeof(raddr);
    while (1) {
        ret = recvfrom(sd, &rcvbuf, sizeof(rcvbuf), 0, (void *)&raddr, &raddrlen);	
        if (ret < 0) {
            perror("recvfrom()");
            goto ERROR3;
        }
        //printf("count:%s, passwd:%s\n", rcvbuf.count, rcvbuf.passwd);
        pid = fork();
        if (pid < 0) {
            perror("fork()");
            goto ERROR3;
        }
        if (pid == 0) {
            //child ---->traval 注册表
            ret = loginhandler(&rcvbuf);
            if (ret == 0) {
                rcvbuf.status = LOGIN_STATUS_OK;
            } else if (ret == 1) {
                rcvbuf.status = LOGIN_STATUS_FAIL;
            } else
                exit(1);
            sendto(sd, &rcvbuf, sizeof(rcvbuf), 0, (void *)&raddr, raddrlen);
            exit(0);
        }
    }

    exit(0);
ERROR1:
    sqlite3_close(db);
    exit(1);
ERROR3:
    close(sd);
ERROR2:
    exit(1);
}

static int loginhandler(const struct login_st *rcv)
{
    sqlite3 *db;
    const char *sql;
    int ret;
    sqlite3_stmt *stmt;
    const char *pwd;
    int retval;

    //打开数据库--》traval注册表---》查看是否有rcv->count帐号---》有则判断密码是否正确 无则失败
    ret = sqlite3_open("../netchat.sqlite3", &db);
    if (ret < 0) {
        fprintf(stderr, "[%d]sqlite3_open() failed\n", __LINE__);
        goto ERROR1;
    }
    sql = "select * from rgsTable where count=?";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, rcv->count, -1, NULL);
    ret = sqlite3_step(stmt);
    if (ret != SQLITE_ROW && ret != SQLITE_DONE) {
        fprintf(stderr, "[%d]sqlite3_step() failed\n", __LINE__);
        goto ERROR2;
    }
    if (ret == SQLITE_ROW) {
        //登录帐号已注册，查看密码是否正确
        pwd = (const char *)sqlite3_column_text(stmt, 2);	
        //printf("pwd:%s, rcv->passwd:%s\n", pwd, rcv->passwd);
        if (strcmp(pwd, rcv->passwd) == 0) {
            //密码正确---》登录成功
            retval = 0;
            //将成功登录的帐号存储到登录表
            sqlite3_finalize(stmt);
            sql = "insert into loginTable(count) values(?)";
            sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
            sqlite3_bind_text(stmt, 1, rcv->count, -1, NULL);
            ret = sqlite3_step(stmt);
            if (ret != SQLITE_DONE) {
                fprintf(stderr, "[%d]sqlite3_step() failed\n", __LINE__);
                goto ERROR2;
            }

        } else {
            retval = 1;
        }
    } else {
        //登录帐号没有注册，则登录失败
        retval = 1;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return retval;

ERROR2:
    sqlite3_finalize(stmt);
    sqlite3_close(db);
ERROR1:
    return -1;
}

