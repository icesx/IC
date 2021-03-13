#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
	int shmid;
	int proj_id;
	key_t key;
	int size;
	char *addr;
	pid_t pid;
	key = IPC_PRIVATE;
	shmid = shmget(key, 1024, IPC_CREAT | 0660);
	if (shmid == -1)
	{
		perror("create share memory failed!");
		return 1;
	}
	addr = (char *)shmat(shmid, NULL, 0);
	if (addr == (char *)(-1))
	{
		perror("cannot attach!");
		return 1;
	}
	printf("share memory segment's address:%x\n", addr);
	strcpy(addr, "welcome to mrsoft!");
	pid = fork();
	if (pid == -1)
	{
		perror("error!!!!");
		return 1;
	}
	else if (pid == 0)
	{
		printf("child process string is' %s'\n", addr);
		_exit(0);
	}
	else
	{
		wait(NULL);
		printf("parent process string is '%s'\n", addr);
		if (shmdt(addr) == -1)
		{
			perror("release failed!");
			return 1;
		}
		if (shmctl(shmid, IPC_RMID, NULL) == -1)
		{
			perror("failed!");
			return 1;
		}
	}
	return 0;
}
