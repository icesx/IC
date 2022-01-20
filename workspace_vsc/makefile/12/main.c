#include "stdio.h"
#include "define.h"
#include "calc/calc.h"
#include "input/getdata.h"
#include "output/putdata.h"
int main()
{  
	int n,k;
	double c;
	getdata(&n,&k);
	c=calculate(n,k);
	putdata(n,k,c); 
	return 0;
}
