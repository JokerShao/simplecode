#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <signal.h>
#include <string.h>

#include "../../client/protocol.h"

static int rgshandler(const struct rgs_st *rcv);
int main(void)
{
    sqlite3 *db = NULL;
    int ret;
    char *errmsg;
    const char *sql;
    int sd;
    struct sockaddr_in laddr, raddr;
    socklen_t raddrlen;
    struct rgs_st rcvbuf;
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
    sql = "create table if not exists rgsTable(no integer primary key autoincrement not null, \
           count text not null, passwd text not null)";
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
    laddr.sin_port = htons(REGISTER_SERVER_PORT);
    inet_aton(REGISTER_SERVER_IP, &laddr.sin_addr);
    if (bind(sd, (void *)&laddr, sizeof(laddr)) < 0) {
        perror("bind()");//errno
        goto ERROR3;
    }

    //收发数据包
    raddrlen = sizeof(raddr);
    while (1) {
        memset(&rcvbuf, '\0', sizeof(rcvbuf));
        ret = recvfrom(sd, &rcvbuf, sizeof(rcvbuf), 0, (void *)&raddr, &raddrlen);	
        if (ret < 0) {
            perror("recvfrom()");
            goto ERROR3;
        }
        printf("debug:recive the message from ip:%s, port:%d\n", inet_ntoa(raddr.sin_addr), ntohs(raddr.sin_port));
        printf("the resgister data count:%s, passwd:%s\n", rcvbuf.count, rcvbuf.passwd);

        pid = fork();
        if (pid < 0) {
            perror("fork()");
            goto ERROR3;
        }
        if (pid == 0) {
            //child ---->traval 注册表
            ret = rgshandler(&rcvbuf);
            if (ret == 0) {
                rcvbuf.status = REGISTER_STATUS_OK;
            } else if (ret == 1) {
                rcvbuf.status = REGISTER_STATUS_FAIL;
            }
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

static int rgshandler(const struct rgs_st *rcv)
{
    sqlite3 *db;
    const char *sql;
    int ret;
    sqlite3_stmt *stmt;
    char sqlarr[128] = {};
    char *errmsg;

    //打开数据库--》traval注册表---》查看是否有rcv->count帐号---》有则status=1 无则status = 0
    ret = sqlite3_open("../netchat.sqlite3", &db);
    if (ret < 0) {
        fprintf(stderr, "sqlite3_open() failed\n");
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
    sqlite3_finalize(stmt);
    if (ret == SQLITE_ROW) {
        //数组库中有注册帐号，不能再次注册
        sqlite3_close(db);	
        return 1;
    } else {
        //可以注册--->将注册帐号插入注册表
        sql = "insert into rgsTable(count,passwd) values(?,?)";
        sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
        sqlite3_bind_text(stmt, 1, rcv->count, -1, NULL);
        sqlite3_bind_text(stmt, 2, rcv->passwd, -1, NULL);
        ret = sqlite3_step(stmt);
        if (ret != SQLITE_DONE) {
            fprintf(stderr, "[%d][%s]sqlite3_step() failed\n", __LINE__, __FUNCTION__);
            goto ERROR2;
        }

        //创建一张与注册帐号同名的表---》用于存放该帐号所有的好友帐号
        snprintf(sqlarr, 128, "create table if not exists %s(no integer primary key autoincrement not null, fcount text not null)", rcv->count);
        ret = sqlite3_exec(db, sqlarr, NULL, NULL, &errmsg);
        if (ret != SQLITE_OK) {
            fprintf(stderr, "[%d][%s] sqlite3_exec():%s \n", __LINE__, __FUNCTION__, errmsg);
            goto ERROR2;
        }
        snprintf(sqlarr, 128, "insert into %s(fcount) values('%s')", rcv->count, rcv->count);
        ret = sqlite3_exec(db, sqlarr, NULL, NULL, &errmsg);
        if (ret != SQLITE_OK) {
            fprintf(stderr, "[%d][%s] sqlite3_exec():%s \n", __LINE__, __FUNCTION__, errmsg);
            goto ERROR2;
        }

        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

ERROR2:
    sqlite3_finalize(stmt);
    sqlite3_close(db);
ERROR1:
    return -1;
}





