#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* fp;
	if ((fp = fopen("file.c", "r+")) == NULL) /*以读写的方式打开一个已存在的文件file.c*/
	{
		perror("Open file textfile");
		exit(1);
	}
	if (fseek(fp, 2, SEEK_SET) != 0)/*将读写位置定位在从文件开头处计算的第2个字节处*/
	{
		perror("Seek file textfile");
		exit(1);
	}
	fputc('m', fp); /*在此处插入字符m*/
	fclose(fp); /*关闭文件*/
	return 0;
}
