﻿#include <sys/types.h>
#include <sys/socket.h> // 包含套接字函数库
#include <stdio.h>
#include <netinet/in.h> // 包含AF_INET相关结构
#include <arpa/inet.h>  // 包含AF_INET相关操作的函数
#include <unistd.h>
#define PORT 3339
int main()
{
   int sockfd;              // 客户套接字标识符
   int len;                 // 客户消息长度
   struct sockaddr_in addr; // 客户套接字地址
   int newsockfd;
   char *buf = "come on!"; //要发送的消息
   int len2;
   char rebuf[40];
   sockfd = socket(AF_INET, SOCK_STREAM, 0); // 创建套接字
   addr.sin_family = AF_INET;                // 客户端套接字地址中的域
   addr.sin_addr.s_addr = htonl(INADDR_ANY);
   addr.sin_port = PORT; // 客户端套接字端口
   len = sizeof(addr);
   newsockfd = connect(sockfd, (struct sockaddr *)&addr, len); //发送连接服务器的请求
   if (newsockfd == -1)
   {
      perror("连接失败");
      return 1;
   }
   len2 = sizeof(buf);
   send(sockfd, buf, len2, 0);  //发送消息
   sleep(10);                   //暂停10秒
   recv(sockfd, rebuf, 256, 0); //接收新消息
   rebuf[sizeof(rebuf) + 1] = '\0';
   printf("receive message:\n%s\n", rebuf); //输出到终端
   close(sockfd);                           // 关闭连接
   return 0;
}
