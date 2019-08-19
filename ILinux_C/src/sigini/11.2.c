#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int i = 0;
void new_handler(int sig) /*SIGINT信号的新的处理方法*/
{
	printf("receive signal number is: %d\n", sig);
	for (; i < 100; i++) /*每隔一秒累加计时*/
	{
		printf("sleep2  %d\n", i);
		sleep(1);
	}
}
int main(void) {
	struct sigaction newact, oldact;
	newact.sa_handler = new_handler; /*处理方法*/
	sigaddset(&newact.sa_mask, SIGQUIT); /*将SIGQUIT信号加到新的处理方法的屏蔽信号中*/
	newact.sa_flags = SA_RESETHAND | SA_NODEFER;
	printf("change SIGINT(2) signal___[ctrl+c]\n");
	sigaction(SIGINT, &newact, &oldact); /*修改SIGINT信号的默认处理方法*/
	while (1) { /*累加计时，直到接收到信号*/
		sleep(1);
		printf("sleep1  %d\n", i);
		i++;
	}
}
