#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
int main(void)
{
	int fd[2], pid, line;
	char message[MAXSIZE];
	/*create pipe*/
	if (pipe(fd) == -1)
	{
		perror("create pipe failed!");
		return 1;
	}
	/*create new process*/
	else if ((pid = fork()) < 0)
	{
		perror("not create a new process!");
		return 1;
	}
	/*child process*/
	else if (pid == 0)
	{
		close(fd[0]);
		printf("child process send message!\n");
		write(fd[1], "Welcome to mrsoft!", 19);
	}
	else
	{
		close(fd[1]);
		printf("parent process receive message is:\n ");
		line = read(fd[0], message, MAXSIZE);
		write(STDOUT_FILENO, message, line);
		printf("\n");
		wait(NULL);
		_exit(0);
	}
	return 0;
}
