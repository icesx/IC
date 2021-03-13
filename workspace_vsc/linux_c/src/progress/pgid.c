#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
	int a;
	pid_t pgid, pid;
	pid = (long)getpid();
	pgid = (long)getpgrp();
	a = setpgid(pid, pgid);
	printf("a=%d,pid=%ld,pgid=%ld\n", a, pid, pgid);
	return 0;
}
