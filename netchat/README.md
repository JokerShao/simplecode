# netchat
A netchat tools on LAN

- Client
    - Client is based on Qt4.7.4

- Server
    - db -> sqlite3
        - open
        - insert
        - delete
    - socket -> UDP
    - fork();
    - io;
    - signal
    
## Note
### 多线程编程
    注册功能：
    进程间通信IPC
    跨主机socket(udp)
    （流式和包式）
    实际中使用的包式居多 
    因为流式的消耗资源太大
    像文件传输 一般使用TCP
    而视频、语音、聊天使用UDP居多
    注意主动端和被动端  而不是服务端和客户端
    存储使用数据库Sqlite
    因为是可以多人同时注册
    所以服务器端需要用到多进程（fork）
    服务器需要建立两张表：注册表、登录表

    注册服务器 登录服务器 聊天服务器 分别部署在三台主机上
    
### 跨主机传输
    结构体单字节对齐
    有两种方法
    1.  __attribute__((packed));
    2.  #pragma pack(1) //只能是2的(1) (2) (4) (8)

