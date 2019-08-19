#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(void) {
	printf("group ID=%d\n", (long) getgid());
	printf("effective group ID=%d\n", (long) getegid());
	return 0;
}
