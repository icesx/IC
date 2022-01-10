#include<dirent.h>
#include<unistd.h>
#include<stdio.h>
main() {
	DIR * dir;
	struct dirent * ptr;
	int i;
	dir = opendir("9.1");/*打开的目录文件*/
	while ((ptr = readdir(dir)) != NULL)/*读取该目录文件中的数据*/
	{
		printf("d_name: %s\n", ptr->d_name);/*输出文件的名字*/
	}
	closedir(dir); /*关闭目录文件*/
}
