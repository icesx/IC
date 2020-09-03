#include "stdio.h"
#include "putdata.h"
void putdata(int n, int k, double data) {
	char prompt[100];
	sprintf(prompt, "%d��ȡ%d�ķ���������%.0lf\n", n, k, data);
	printf(prompt);
}
