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

static int chathandler(struct chat_st *rcv, int sd);

int main(void)
{
    sqlite3 *db = NULL;
    int ret;
    char *errmsg;
    const char *sql;
    int sd;
    struct sockaddr_in laddr, raddr;
    socklen_t raddrlen;
    struct chat_st rcvbuf;
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
    sql = "create table if not exists chatTable(no integer primary key autoincrement not null, \
           scount text not null, dcount text not null, msg text not null)";
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
    laddr.sin_port = htons(CHAT_SERVER_PORT);
    inet_aton(CHAT_SERVER_IP, &laddr.sin_addr);
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
            //child ---->traval 
            ret = chathandler(&rcvbuf, sd);
            if (ret < 0) {
                ERRORMSG(chathandler);
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

static int chathandler(struct chat_st *rcv, int sd)
{
    sqlite3 *db;
    const char *sql;
    int ret;
    sqlite3_stmt *stmt;
    struct chat_st sndbuf;
    struct sockaddr_in *daddr;

    //查找地址表中是否有dcount地址，如果有则转发，如果没有则不转发
    sqlite3_open("../netchat.sqlite3", &db);

    sql = "select * from rmbaddrTable where count=?";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, rcv->dcount, -1, NULL);
    ret = sqlite3_step(stmt);
    if (ret != SQLITE_ROW && ret != SQLITE_DONE) {
        ERRORMSG(sqlite3_step());
        goto step_error;
    }
    if (ret == SQLITE_ROW) {
        //地址表中有存储dcount地址--->获取其地址 转发
        daddr = (void *)sqlite3_column_blob(stmt, 2);
        rcv->status = CHAT_STATUS_MSG;
        sendto(sd, rcv, sizeof(*rcv), 0, (void *)daddr, sizeof(*daddr));	
    } 
    sqlite3_finalize(stmt);
    sql = "insert into chatTable(scount, dcount, msg) values(?,?,?)";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, rcv->scount, -1, NULL);
    sqlite3_bind_text(stmt, 2, rcv->dcount, -1, NULL);
    sqlite3_bind_text(stmt, 3, rcv->msg, -1, NULL);
    ret = sqlite3_step(stmt);
    if (ret != SQLITE_DONE) {
        ERRORMSG(sqlite3_step());
        goto step_error;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;

step_error:
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return -1;
}
