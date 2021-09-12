#include "stdio.h"
#include "putdata.h"
void putdata(int n,int k,double data)
{ char prompt[100];
  sprintf(prompt,"%d中取%d的方法总数是%.0lf\n",n,k,data);
  printf(prompt);
}
