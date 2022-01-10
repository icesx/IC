#include<stdio.h>
#include<unistd.h>
#include<limits.h>
int main() {
	char a[PATH_MAX]; /*存放工作目录的字符串*/
	if (getcwd(a, PATH_MAX) == NULL) /*获取当前工作目录*/
	{
		perror("getcwd failed!");
		return 1;
	}
	printf("输出当前工作目录：%s\n", a); /*输出字符数组*/
	return 0;
}
