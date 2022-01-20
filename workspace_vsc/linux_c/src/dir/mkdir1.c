#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
int mkdir(char *dir)
{
	if (mkdir(dir, 0700) == -1) /*调用创建新目录的函数*/
	{
		perror("create failed!");
		return 1;
	}
	printf("create hello successful!\n");
	return 0;
}
