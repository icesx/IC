#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    key_t key;
    int proj_id = 1;
    int msqid;
    struct msgbuf
    {
        long msgtype;
        char msgtext[1024];
    } snd, rcv;
    key = ftok(".", proj_id); /*创建新进程*/
    if (key == -1)
    {
        perror("获取键值错误!");
        return 1;
    }
    if ((msqid = msgget(key, IPC_CREAT | 0666)) == -1) /*创建消息队列*/
    {
        printf("创建消息队列错误!\n");
        exit(1);
    }
    printf("创建消息队列成功!\n");

    if (msgctl(msqid, IPC_RMID, 0) != 0) /*删除新创建的消息队列*/
    {
        printf("删除消息队列错误!\n");
        exit(1);
    }
    printf("删除消息队列成功!\n");
    exit(0);
}
