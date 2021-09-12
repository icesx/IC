#include "stdio.h"
#include "clang.h"
void make_define()
{
	double r, s;
	printf("Input r:");
	scanf("%lf", &r);
	s = AREA(r);
	printf("radio=%lf,Area=%lf\n", r, s);
	printf("max=%d",MAX(2,6));
}