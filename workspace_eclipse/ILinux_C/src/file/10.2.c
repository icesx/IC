#include<stdio.h>

int main() {
	FILE *fp;
	int i;
	char *path = "test.c";
	char a[] = { 'h', 'e', 'l', 'l', 'o', ' ', 'm', 'r' };
	char ch;
	fp = fopen(path, "w");/*以只写打开文件*/
	if (fp) /*判断是否成功打开文件*/
	{

		for (i = 0; i < 5; i++) {

			if (fputc(a[i], fp) == EOF)/*向文件中循环写入a数组中的内容*/
			{
				perror("write error!");
				return 1;
			}
		}

		printf("write successful!\n");
	} else {
		printf("open error!\n");
		return 1;
	}
	fclose(fp); /*关闭文件*/
	if ((fp = fopen("test.c", "r")) == NULL)/*以只读的形式打开文件*/
	{
		perror("open error!");
		return 1;
	}
	printf("output data in the test.c\n");
	for (i = 0; i < 5; i++) {
		if ((ch = fgetc(fp)) == EOF)/*循环方式获取文件中的5个字节*/
		{
			perror("fgetc error!");
			return 1;
		} else {
			printf("%c", ch);/*输出字符*/
		}
	}
	printf("\nget successful!\nplease examine test.c...\n");
	fclose(fp);/*关闭文件*/
	return 0;

}
