#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
void exit_s(int status) {
	if (WIFEXITED(status))
		printf("normal exit,status=%d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("signal exit!status=%d\n", WTERMSIG(status));
}
int main(void) {
	pid_t pid, pid1;
	int status;
	if ((pid = fork()) < 0) {
		printf("child process error!\n");
		exit(0);
	} else if (pid == 0) {
		printf("the child process!\n");
		exit(2);
	}
	if (wait(&status) != pid) {
		printf("this is a parent process!\nwait error!\n");
		exit(0);
	}
	exit_s(status);
	if ((pid = fork()) < 0) {
		printf("child process error!\n");
		exit(0);
	} else if (pid == 0) {
		printf("the child process!\n");
		pid1 = getpid();
		//	kill(pid1,9);
		//	kill(pid1,17);
		kill(pid1, 19);
	}
	if (wait(&status) != pid) {
		printf("this is a parent process!\nwait error!\n");
		exit(0);
	}
	exit_s(status);

	exit(0);

}
