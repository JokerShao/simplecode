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

#define ERRORMSG(fun) \
    fprintf(stderr, "[%s][%d]%s error\n",  __FUNCTION__, __LINE__, #fun);


static int rmbhandler(const struct rmb_st *rcv, int sd, const struct sockaddr_in *raddr);
int main(void)
{
    sqlite3 *db = NULL;
    int ret;
    char *errmsg;
    const char *sql;
    int sd;
    struct sockaddr_in laddr, raddr;
    socklen_t raddrlen;
    struct rmb_st rcvbuf;
    pid_t pid;
    struct sigaction act;


    //使得子进程不变成僵尸进程
    act.sa_handler = SIG_IGN;
    act.sa_flags = SA_NOCLDWAIT;
    sigaction(SIGCHLD, &act, NULL);

    ret = sqlite3_open("../netchat.sqlite3", &db);
    if (ret != SQLITE_OK) {
        fprintf(stderr, "sqlite3_open() failed\n");
        exit(1);
    }
    sql = "create table if not exists rmbaddrTable(no integer primary key autoincrement not null, \
           count text not null, addr blob not null)";
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

    //初始化与客户端通信的报式套接字
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sd < 0) {
        perror("socket()");
        goto ERROR2;
    }

    laddr.sin_family = AF_INET;//ipv4
    laddr.sin_port = htons(RMB_SERVER_PORT);
    inet_aton(RMB_SERVER_IP, &laddr.sin_addr);
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
        pid = fork();
        if (pid < 0) {
            perror("fork()");
            goto ERROR3;
        }
        if (pid == 0) {
            //child ---->traval 注册表
            ret = rmbhandler(&rcvbuf, sd, &raddr);
            if (ret < 0) {
                ERRORMSG(rmbhandler);
                exit(1);
            }

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

static int rmbhandler(const struct rmb_st *rcv, int sd, const struct sockaddr_in *raddr)
{
    sqlite3 *db;
    const char *sql;
    int ret;
    sqlite3_stmt *stmt;
    char sqlarr[128] = {};
    const char *fcount;
    struct chat_st sndbuf;

    //存储登录帐号的地址  变量该帐号的好友列表，将所有的好友发送给客户端
    ret = sqlite3_open("../netchat.sqlite3", &db);	
    if (ret != SQLITE_OK) {
        ERRORMSG(sqlite3_open);
        return -1;
    }
    //查看帐号是否已经记录过地址，有则更新，无则插入
    sql = "select * from rmbaddrTable where count=?";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, rcv->count, -1, NULL);
    ret = sqlite3_step(stmt);
    if (ret != SQLITE_ROW && ret != SQLITE_DONE) {
        ERRORMSG(sqlite3_step());
        goto step_error;
    }
    if (ret == SQLITE_ROW) {
        //已经再地址表中
        printf("the addrTable has the address\n");
        sql = "update rmbaddrTable set addr=? where count=?";
    } else {
        sql = "insert into rmbaddrTable(addr, count) values(?,?)";
    }
    sqlite3_finalize(stmt);
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 2, rcv->count, -1, NULL);
    sqlite3_bind_blob(stmt, 1, raddr, sizeof(*raddr), NULL);
    ret = sqlite3_step(stmt);
    if (ret != SQLITE_DONE) {
        ERRORMSG(sqlite_step);
        goto step_error;
    }

    sqlite3_finalize(stmt);
    snprintf(sqlarr, 128, "select * from %s", rcv->count);		
    sqlite3_prepare_v2(db, sqlarr, -1, &stmt, NULL);
    while (1) {
        ret = sqlite3_step(stmt);	
        if (ret != SQLITE_ROW && ret != SQLITE_DONE) {
            ERRORMSG(sqlite_step);
            goto step_error;

        }
        if (ret != SQLITE_ROW)
            break;
        else {
            fcount = (const char *)sqlite3_column_text(stmt, 1);	
            strcpy(sndbuf.dcount, fcount);
            sndbuf.status = CHAT_STATUS_LIST;
            sendto(sd, (void *)&sndbuf, sizeof(sndbuf), 0, (void *)raddr, sizeof(*raddr));	
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;

step_error:
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return -1;
}





