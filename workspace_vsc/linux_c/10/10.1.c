#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	char *path = "test.c"; /*进行操作的文件路径*/
	int fd;
	char buf[40], buf2[] = "hello mrcff"; /*自定义读写用的缓冲区*/
	int n, i;
	if ((fd = open(path, O_RDWR)) < 0) /*打开文件*/
	{
		perror("open file failed!");
		return 1;
	}
	else
		printf("open file successful!\n");
	if ((n = read(fd, buf, 20)) < 0) /*读取文件中的数据*/
	{
		perror("read failed!");
		return 1;
	}
	else
	{
		printf("output read data:\n");
		printf("%s\n", buf); /*将读取的数据输出到终端控制台*/
	}
	if ((i = lseek(fd, 11, SEEK_SET)) < 0) /*定位到从文件开头处到第11个字节处*/
	{
		perror("lseek  error!");
		return 1;
	}
	else
	{
		if (write(fd, buf2, 11) < 0) /*向文件中写入数据*/
		{
			perror("write error!");
			return 1;
		}
		else
		{
			printf("write successful!\n");
		}
	}
	close(fd); /*关闭文件的同时保存了对文件的改动*/

	if ((fd = open(path, O_RDWR)) < 0) /*打开文件*/
	{
		perror("open file failed!");
		return 1;
	}
	if ((n = read(fd, buf, 40)) < 0) /*读取数据*/
	{
		perror("read 2 failed!");
		return 1;
	}
	else
	{
		printf("read the changed data:\n");
		printf("%s\n", buf); /*将数据输出到终端*/
	}
	if (close(fd) < 0) /*关闭文件*/
	{
		perror("close failed!");
		return 1;
	}
	else
		printf("good bye!\n");
	return 0;
}
