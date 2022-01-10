#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *oldpath = "new.c";		  /*原文件路径*/
	char *newpath = "new2.c";		  /*新硬链接文件路径*/
	if (link(oldpath, newpath) == -1) /*创建一个硬联接*/
	{
		perror("create hard link failed!");
		return 1;
	}
	printf("create hard link successful!\n");
	if (open(newpath, O_RDWR) < 0) /*打开这个硬链接*/
	{
		perror("open error!");
		return 1;
	}
	printf("open successful!\n");
	sleep(20);				 /*暂停10秒*/
	if (unlink(newpath) < 0) /*删除硬链接文件*/
	{
		perror("unlink error!");
		return 1;
	}
	printf("file unlink!\n");
	sleep(10);
	printf("well done!\n");
	return 0;
}
