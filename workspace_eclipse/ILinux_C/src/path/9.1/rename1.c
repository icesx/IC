#include<stdio.h>
int main(int argc, char *argv[]) {
	if (argc < 3) /*从终端传递的参数小于3时，说明该程序的用法*/
	{
		printf("usages:%s oldpath newpath\n", argv[0]);
		return 1;
	}
	if (rename(argv[1], argv[2]) < 0)/*调用函数将argv[1]的名字改为argv[2]的名字*/
	{
		printf("failed!\n");
		return 1;
	} else {/*函数调用成功*/
		printf("%s=>%s\nsuccessful!\n", argv[1], argv[2]);

	}
	return 0;
}
