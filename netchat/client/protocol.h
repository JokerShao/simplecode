#ifndef PROTOCOL_H
#define PROTOCOL_H

#pragma pack(1)

#define DEFAULT_SERVER_IP   "192.168.0.106"

//注册
#define REGISTER_SERVER_IP          DEFAULT_SERVER_IP
#define REGISTER_SERVER_PORT     1111
#define SIZE                                    64
#define REGISTER_STATUS_OK          0
#define REGISTER_STATUS_FAIL        1

struct rgs_st {
    char count[SIZE];
    char passwd[SIZE];
    int status;//server给client发送注册成功与否
}__attribute__((packed));

//登录
#define LOGIN_SERVER_IP                 DEFAULT_SERVER_IP
#define LOGIN_SERVER_PORT            2222
#define LOGIN_STATUS_OK                0
#define LOGIN_STATUS_FAIL              1

struct login_st {
    char count[SIZE];
    char passwd[SIZE];
    int status;//server给client发送注册成功与否
};

//添加好友
#define ADDFRD_SERVER_IP             DEFAULT_SERVER_IP
#define ADDFRD_SERVER_PORT        3333
#define ADDFRD_STATUS_ALREADY   1
#define ADDFRD_STATUS_NOEXIST    2
#define ADDFRD_STATUS_OK            0
struct addfrd_st {
    char scount[SIZE];
    char dcount[SIZE];
    int status;
};

//记住地址
#define RMB_SERVER_IP                 DEFAULT_SERVER_IP
#define RMB_SERVER_PORT            4444
struct rmb_st {
    char count[SIZE];
};

//聊天
#define CHAT_SERVER_IP              DEFAULT_SERVER_IP
#define CHAT_SERVER_PORT         5555
#define CHAT_STATUS_LIST           0
#define CHAT_STATUS_MSG          1
#define MSGSIZE                          1024
struct chat_st {
    char scount[SIZE];
    char dcount[SIZE];
    char msg[MSGSIZE];
    int status;
};

#endif // PROTOCOL_H
