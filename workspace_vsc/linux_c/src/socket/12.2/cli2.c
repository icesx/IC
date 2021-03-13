/*客户端*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define PORT 8886

int main(int argc, char **argv)
{//定义变量
	struct sockaddr_in s_addr;	//套接字地址结构
	int sock;			//套接字描述符
	int addr_len;			//地址结构长度
	int len;			//发送字节长度
	char buff[]="Hello everyone,Merry Christmas!";	//发送的消息
/* 创建数据报模式的套接字 */
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket error");
		exit(errno);
	}
       	else
		printf("create socket successful.\n\r");
/* 设置对方地址和端口信息 */
	s_addr.sin_family = AF_INET; 	//地址族
//	if (argv[2])
//		s_addr.sin_port = htons(atoi(argv[2]));
//	else
		s_addr.sin_port = htons(PORT);
	if (argv[1])
		s_addr.sin_addr.s_addr = inet_addr(argv[1]);
	else {
		printf("没有输入消息的接受者！\n");
		exit(0);
	}
	addr_len = sizeof(s_addr);	//地址结构长度
/*从客户端的buff缓冲区中发送消息到地址结构为s_addr的远端机器*/
	len = sendto(sock, buff, sizeof(buff), 0,(struct sockaddr *) &s_addr, addr_len);
	if (len < 0) {			//如果发送失败
		printf("\n\rsend error.\n\r");
		return 3;
	}
	printf("send success.\n\r");	//发送成功
	return 0;
}
