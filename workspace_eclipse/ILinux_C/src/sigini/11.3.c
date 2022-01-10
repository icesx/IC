#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
static void sig_handler(int signo) /*自定义的信号SIGINT处理函数*/
{
	printf("信号SIGINT 被捕捉！\n ");
}
int main() {
	sigset_t new, old, pend;
	if (signal(SIGINT, sig_handler) == SIG_ERR) /*注册一个信号处理函数sig_handler*/
	{
		perror("signal");
		exit(1);
	}
	if (sigemptyset(&new) < 0) /*清空信号集*/
		perror("sigemptyset");
	if (sigaddset(&new, SIGINT) < 0) /*向new信号集中添加SIGINT信号*/
		perror("sigaddset");
	if (sigprocmask(SIG_SETMASK, &new, &old) < 0) /*将信号集new阻塞*/
	{
		perror("sigprocmask");
		exit(1);
	}
	printf("SIGQUIT被阻塞！\n ");
	printf("试着按下Ctrl+ C，程序会暂停5秒等待处理事件！ \n");
	sleep(5);
	if (sigpending(&pend) < 0) /*获得未决的信号类型*/
		perror("sigpending");
	if (sigismember(&pend, SIGINT)) /*检查SIGINT信号是否为未决的信号类型*/
		printf("信号SIGINT未决\n ");
	if (sigprocmask(SIG_SETMASK, &old, NULL) < 0) /*恢复为原始的信号掩码，解开阻塞*/
	{
		perror("sigprocmask");
		exit(1);
	}
	printf(" SIGINT已被解开阻塞 \n");
	printf("再试着按下Ctrl +C  \n");
	sleep(5);
	return 0;
}
