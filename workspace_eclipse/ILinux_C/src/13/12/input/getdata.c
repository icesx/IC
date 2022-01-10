#include "stdio.h"
#include "getdata.h"
void getdata(int *n, int*k) {
	char prompt[100];
	sprintf(prompt, "��������������(С��%d) ", FACMAX);
	*n = input(prompt);
	do {
		sprintf(prompt, "������ȡ����(С��%d����%d) ", FACMAX, *n);
		*k = input(prompt);
	} while (n < k);
}
int input(char *prompt) {
	int x;
	do {
		printf(prompt);
		scanf("%d", &x);

	} while (x <= 0 || x > FACMAX);
	return x;
}
