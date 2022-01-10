/*服务器端*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define PORT 8886

int main(int argc, char **argv) {
	struct sockaddr_in s_addr;	//服务器地址结构
	struct sockaddr_in c_addr;	//客户端地址结构
	int sock;			//套接字描述符
	socklen_t addr_len;		//地址结构长度
	int len;			//接收到的消息字节数
	char buff[128];			//存放接收消息的缓冲区
	/* 创建数据报模式的套接字 */
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(errno);
	} else
		printf("create socket successful.\n\r");
	/*清空地址结构*/
	memset(&s_addr, 0, sizeof(struct sockaddr_in));
	/* 设置地址和端口信息 */
	s_addr.sin_family = AF_INET;
//	if (argv[2])
//		s_addr.sin_port = htons(atoi(argv[2]));
//	else
	s_addr.sin_port = htons(PORT);
//	if (argv[1])
//		s_addr.sin_addr.s_addr = inet_addr(argv[1]);
//	else
	s_addr.sin_addr.s_addr = INADDR_ANY;
	/* 绑定地址和端口信息 */
	if ((bind(sock, (struct sockaddr *) &s_addr, sizeof(s_addr))) == -1) {
		perror("bind error");
		exit(errno);
	} else
		printf("bind address to socket successfuly.\n\r");
	/* 循环接收数据 */
	addr_len = sizeof(c_addr);
	while (1) {
		len = recvfrom(sock, buff, sizeof(buff) - 1, 0,
				(struct sockaddr *) &c_addr, &addr_len);
		if (len < 0) {			//接收失败
			perror("recvfrom error");
			exit(errno);
		}
		buff[len] = '\0';
		printf("收到来自远端计算机%s，端口号为%d的消息:\n%s\n\r", inet_ntoa(c_addr.sin_addr),
				ntohs(c_addr.sin_port), buff);
	}
	return 0;
}
