#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(void) 
{
    pid_t pid;
    struct sigaction act;

    //使得子进程不变成僵尸进程
    act.sa_handler = SIG_IGN;
    act.sa_flags = SA_NOCLDWAIT;
    sigaction(SIGCHLD, &act, NULL);

    pid = fork();
    if (pid == 0) {
        //child
        printf("the server of register is starting\n");
        execl("./bin/rgs_server", "./bin/rgs_server", NULL);	
        perror("execl()");
        exit(1);
    }

    sleep(1);

    pid = fork();
    if (pid == 0) {
        printf("the server of login is starting\n");
        execl("./bin/login_server", "./bin/login_server", NULL);
        perror("execl()");
        exit(1);
    }

    sleep(1);
    pid = fork();
    if (pid == 0) {
        printf("the server of addfrd is starting\n");
        execl("./bin/addfrd_server", "./bin/addfrd_server", NULL);
        perror("execl()");
        exit(1);
    }

    sleep(1);
    pid = fork();
    if (pid == 0) {
        printf("the server of rmbaddr is starting\n");
        execl("./bin/rmbaddr_server", "./bin/rmbaddr_server", NULL);
        perror("execl()");
        exit(1);
    }

    sleep(1);
    pid = fork();
    if (pid == 0) {
        printf("the server of chat is starting\n");
        execl("./bin/chat_server", "./bin/chat_server", NULL);
        perror("execl()");
        exit(1);
    }

    while (1)
        pause();


    exit(0);
}






