//输入两个数n,和k保证n>=k
#include "stdio.h"
#include "getdata.h"
void getdata(int *n,int*k)
{
   char prompt[100];
   sprintf(prompt,"请输入样本总数(<%d) ",FACMAX);
   *n=input(prompt);
   do{
     sprintf(prompt,"请输入取样数(<%d>=%d) ",FACMAX,*n);
     *k=input(prompt);
   }while(n<k);
}
//输入一个0到FACMAX之间的数
int input(char *prompt)
{
	int x;
	do{
		printf(prompt);
		scanf("%d",&x);

	}while(x<=0||x>FACMAX);
	return x;
}
