#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int main()
{
	char *oldpath = "eq1.c";	/*原文件路径, 要保证在当前目录下存在这个文件*/
	char *newpath = "symbol.c"; /*新符号链接文件路径*/
	char buf[200];
	if (symlink(oldpath, newpath) == -1) /*创建一个符号链接*/
	{
		perror("创建符号链接失败!");
		return 1;
	}
	printf("创建符号链接成功!\n");
	memset(buf, 0, 200);
	if (readlink(newpath, buf, 200) < 0) /*打开这个符号链接*/
	{
		perror("打开失败!");
		return 1;
	}
	printf("打开成功!\n");
	printf("通过符号链接获取文件名：%s\n", buf);
	sleep(10);				 /*暂停10秒*/
	if (unlink(newpath) < 0) /*删除符号链接文件*/
	{
		perror("删除符号链接失败!");
		return 1;
	}
	printf("符号链接已删除!\n");
	sleep(10);
	printf("操作结束!\n");
	return 0;
}
