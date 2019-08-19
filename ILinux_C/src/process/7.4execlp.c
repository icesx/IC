#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("vi的等效用法： %s filename\n", argv[0]);
		return 1;
	}
	execlp("/bin/vi", "vi", argv[1], (char*) NULL);
	return 0;
}
