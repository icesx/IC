#include <sys/types.h>
#include <sys/socket.h>							// 包含套接字函数库
#include <stdio.h>
#include <netinet/in.h>							// 包含AF_INET相关结构
#include <arpa/inet.h>							// 包含AF_INET相关操作的函数
#include <unistd.h>
#define PORT 5210
int main()
{
   int count;	
   int sendsum=0;
   int buf[10];
   int s_fd, c_fd;	// 服务器和客户套接字标识符
   int s_len, c_len;			// 服务器和客户消息长度
   struct sockaddr_in s_addr;	// 服务器套接字地址
   struct sockaddr_in c_addr;	// 客户套接字地址
   s_fd = socket(AF_INET, SOCK_STREAM, 0);	// 创建套接字
   s_addr.sin_family = AF_INET;	// 定义服务器套接字地址中的域
   s_addr.sin_addr.s_addr=htonl(INADDR_ANY);							// 定义套接字地址
   s_addr.sin_port = PORT;		// 定义服务器套接字端口
   s_len = sizeof(s_addr);
   bind(s_fd, (struct sockaddr *) &s_addr, s_len);	// 綁定套接字与设置的端口号
   listen(s_fd, 10);			// 监听状态，守候进程
   while (1) {
      printf("please wait a moment!\n");
      c_len = sizeof(c_addr);
//接收客户端连接请求
      c_fd = accept(s_fd,(struct sockaddr *) &c_addr,(socklen_t *__restrict) &c_len);
      recv(c_fd,buf,50,0); //接收消息
      for(count=0;count<10;count++)
      {
      printf("receive message:\n %d\n",buf[count]);//输出到终端
      sendsum+=buf[count];
      }
      printf("add= %d\n",sendsum);//输出到终端
      send(c_fd,&sendsum,sizeof(sendsum),0);//回复消息
close(c_fd);							// 关闭连接
   }
}
