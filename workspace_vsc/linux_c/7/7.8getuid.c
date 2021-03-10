#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int main(void)
{
	printf("UID=%ld\n",(long)getuid());
	printf("EUID=%ld\n",(long)geteuid());
	return 0;
}
