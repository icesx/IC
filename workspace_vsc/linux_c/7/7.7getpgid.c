#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(void)
{

	printf("进程ID:%ld\n",(long)getpid());
	printf("父进程ID:%ld\n",(long)getppid());
	return 0;
}
