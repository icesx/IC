#include<string.h>
#include<stdio.h> 
int main(void) {
	char s[] = "welcome to mrsoft\n";
	printf("s before memset: %s\n", s);
	memset(s, '*', strlen(s) - 1);
	printf("s after memset: %s\n", s);
	return 0;
}
