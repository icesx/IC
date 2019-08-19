#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc, char* argv[]) {
	execl("hello", argv[0], NULL);
}
