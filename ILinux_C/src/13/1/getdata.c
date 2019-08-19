//����������n,��k��֤n>=k
#include "stdio.h"
#include "getdata.h"
void getdata(int *n, int*k) {
	char prompt[100];
	sprintf(prompt, "��������������(<%d) ", FACMAX);
	*n = input(prompt);
	do {
		sprintf(prompt, "������ȡ����(<%d>=%d) ", FACMAX, *n);
		*k = input(prompt);
	} while (n < k);
}
//����һ��0��FACMAX֮�����
int input(char *prompt) {
	int x;
	do {
		printf(prompt);
		scanf("%d", &x);

	} while (x <= 0 || x > FACMAX);
	return x;
}
