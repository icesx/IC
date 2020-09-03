#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sigfunc(int signo) {
	/* nothing to do */
}

unsigned int mysleep(unsigned int second) {
	struct sigaction newact, oldact;
	unsigned int stop;

	newact.sa_handler = sigfunc;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGALRM, &newact, &oldact);
	alarm(second);
	pause();
	stop = alarm(0);
	sigaction(SIGALRM, &oldact, NULL);

	return stop;
}

int main(void) {
	int s;
	printf("input seconds of sleep!\nsecond=");
	scanf("%d", &s);
	while (1) {
		mysleep(s);
		printf("%d seconds passed\n", s);
	}
	return 0;
}
