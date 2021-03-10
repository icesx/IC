#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)
{
	pid_t pid;
	if((pid=fork())<0)				/*创建新进程*/
	{
		printf("fork error!\n");
		exit(1);
	}
	else if(pid==0)					/*新创建的子进程*/
	{
		printf("hello world!\n");
	}
	else 
	{
		printf("welcome to mrsoft\n");
	}
	exit(0);
}