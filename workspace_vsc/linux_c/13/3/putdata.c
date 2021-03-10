 //输出程序结果
#include "stdio.h"
#include "putdata.h"
//输出
void putdata(int n,int k,double data)
{ char prompt[100];
  sprintf(prompt,"%d中取%d的方法总数是%.0lf\n",n,k,data);
  printf(prompt);
}
