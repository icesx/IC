#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
extern char **environ;
int main(int argc, char* argv[]) {
	/*	execve("new",argv,environ);
	 puts("正常情况下无法输出此信息");
	 */
	pid_t pid;
	if ((pid = fork()) < 0)
		printf("create child process failed!\n");
	else if (pid == 0)
		execve("new", argv, environ);
	else
		puts("正常情况下无法输出此信息");

}

