#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(void) {
	int flag1, flag2;
	flag1 = setuid(0);
	flag2 = setgid(500);
	printf("flag1=%d\n,flag2=%d\n", flag1, flag2);
	return 0;

}
