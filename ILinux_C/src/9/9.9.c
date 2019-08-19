#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
int main() {
	char dir[20] = "新目录"; /*创建的新目录*/
	if (mkdir(dir, 0700) == -1) /*调用创建新目录的函数*/
	{
		perror("创建新目录失败!");
		return 1;
	}
	printf("创建新目录成功!\n");
	sleep(3);
	if (rmdir(dir) == -1) /*调用删除目录的函数*/
	{
		perror("删除目录失败!");
		return 1;
	}
	printf("删除目录成功!\n");
	return 0;
}
