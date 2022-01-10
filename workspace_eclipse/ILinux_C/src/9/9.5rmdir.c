#include<stdio.h>
#include<unistd.h>
int main() {
	char* dir = "hello";
	if (rmdir(dir) == -1) {
		perror("failed!");
		return 1;
	}
	printf("remove successful!\n");
	return 0;
}
