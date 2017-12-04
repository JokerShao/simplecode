#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sqlite3.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <signal.h>

#include "../../client/protocol.h"

static int addfrdhandler(const struct addfrd_st *rcv);
int main(void)
{
    sqlite3 *db = NULL;
    int ret;
    char *errmsg;
    const char *sql;
    int sd;
    struct sockaddr_in laddr, raddr;
    socklen_t raddrlen;
    struct addfrd_st rcvbuf;
    pid_t pid;
    struct sigaction act;

    //使得子进程不变成僵尸进程
    act.sa_handler = SIG_IGN;
    act.sa_flags = SA_NOCLDWAIT;
    sigaction(SIGCHLD, &act, NULL);

    //初始化与客户端通信的报式套接字
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sd < 0) {
        perror("socket()");
        goto ERROR2;
    }

    laddr.sin_family = AF_INET;//ipv4
    laddr.sin_port = htons(ADDFRD_SERVER_PORT);
    inet_aton(ADDFRD_SERVER_IP, &laddr.sin_addr);
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
            ret = addfrdhandler(&rcvbuf);
            if (ret == 0) {
                rcvbuf.status = ADDFRD_STATUS_OK;
            } else if (ret == 1) {
                rcvbuf.status = ADDFRD_STATUS_ALREADY;
            } else if (ret == 2) {
                rcvbuf.status = ADDFRD_STATUS_NOEXIST;	
            } else {
                exit(1);
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

static int addfrdhandler(const struct addfrd_st *rcv)
{
    sqlite3 *db;
    const char *sql;
    int ret;
    sqlite3_stmt *stmt;
    /* const char *pwd; */
    int retval;
    char sqlarr[128] = {};

    //查看添加好友的好友帐号是否再登录表中，如果在登录表中，查看此帐号是否已经是我的好友，如果是则返回ADDFRD_STATUS_ALREADY，不是则返回ADDFRD_STATUS_OK，如果不在登录表中，则返回ADDFRD_STATUS_NOEXIST
    sqlite3_open("../netchat.sqlite3", &db);
    sql = "select * from loginTable where count=?";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, rcv->dcount, -1, NULL);
    ret = sqlite3_step(stmt);
    if (ret != SQLITE_ROW && ret != SQLITE_DONE) {
        fprintf(stderr, "[%s][%d]sqlite3_step() error\n", __FUNCTION__, __LINE__);
        goto step_error;
    }
    sqlite3_finalize(stmt);

    if (ret == SQLITE_ROW) {
        //好友帐号存在在登录表中---》查看是否再好友列表中
        snprintf(sqlarr, 128, "select * from %s where fcount=?", rcv->scount);	
        sqlite3_prepare_v2(db, sqlarr, -1, &stmt, NULL);
        sqlite3_bind_text(stmt, 1, rcv->dcount, -1, NULL);
        ret = sqlite3_step(stmt);
        if (ret != SQLITE_ROW && ret != SQLITE_DONE) {
            fprintf(stderr, "[%s][%d]sqlite3_step() error\n", __FUNCTION__, __LINE__);
            goto step_error;
        }
        sqlite3_finalize(stmt);
        if (ret == SQLITE_ROW) {
            //already		
            retval = ADDFRD_STATUS_ALREADY;
        } else {
            retval = ADDFRD_STATUS_OK;
            //好友添加成功，将此好友帐号写入好友列表
            snprintf(sqlarr, 128, "insert into %s(fcount) values('%s')", rcv->scount, rcv->dcount);
            sqlite3_prepare_v2(db, sqlarr, -1, &stmt, NULL);
            ret = sqlite3_step(stmt);
            if (ret != SQLITE_DONE) {
                fprintf(stderr, "[%s][%d]sqlite3_step() error\n", __FUNCTION__, __LINE__);
                goto step_error;
            }
            sqlite3_finalize(stmt);

            //登录帐号也要在好友的好友列表中
            snprintf(sqlarr, 128, "insert into %s(fcount) values('%s')", rcv->dcount, rcv->scount);
            sqlite3_prepare_v2(db, sqlarr, -1, &stmt, NULL);
            ret = sqlite3_step(stmt);
            if (ret != SQLITE_DONE) {
                fprintf(stderr, "[%s][%d]sqlite3_step() error\n", __FUNCTION__, __LINE__);
                goto step_error;
            }
            sqlite3_finalize(stmt);

        }
    } else {
        retval = ADDFRD_STATUS_NOEXIST;
    }

    sqlite3_close(db);
    return retval;

step_error:
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return -1;
}
