#include "stdio.h"
#include "define.h"
#include "calc/calc.h"
#include "input/getdata.h"
#include "output/putdata.h"
//计算n个样品中取出k个样品的组合方式有多少种
int main()
{
	int n,k;
	double c;
	getdata(&n,&k);
	c=calculate(n,k);
	putdata(n,k,c); 
} 
