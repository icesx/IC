#include "stdio.h"
#include "clang.h"
#define PI 3.142
#define AREA(r) PI *(r) * (r)
void make_define()
{
	double r, s;
	printf("Input r:");
	scanf("%lf", &r);
	s = AREA(r);
	printf("radio=%lf,Area=%lf\n", r, s);
}