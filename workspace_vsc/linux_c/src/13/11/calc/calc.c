#include "calc.h"
//计算n个样品中取k个样品的组合方式有多少种
double calculate(int n,int k)
{
	return factorial(n)/(factorial(k)*factorial(n-k));
}
//计算n的阶乘
double factorial(int n)
{
	double s=1;
	int i;
	for(i=1;i<=n;i++)
		s=s*i;
	return s;
}
