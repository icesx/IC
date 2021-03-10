#include<stdio.h>
#include<stdlib.h>
main()
{
    FILE *fp;
    char ch,filename[50];
    printf("请输入文件路径及名称:\n");
    scanf("%s",filename);							/*输入文件名*/
    if((fp=fopen(filename,"r"))==NULL) 				/*以只读方式打开该文件*/
    {
        printf("不能打开的文件!\n");
        exit(0);
    }
printf("len0=%d\n",ftell(fp));				/*输出当前位置*/
    ch = fgetc(fp);
    while (ch != EOF)
    {
        putchar(ch);								/*输出字符*/
        ch = fgetc(fp); 							/*获取fp指向文件中的字符*/
    }
    printf("\n");
printf("len1=%d\n",ftell(fp));   			/*输出位置指针的当前位置*/ 
rewind(fp);						/*指针指向文件开头*/
printf("len2=%d\n",ftell(fp));				/*输出位置指针当前位置*/
    ch = fgetc(fp);	
    while (ch != EOF)
    {
        putchar(ch); 							/*输出字符*/
        ch = fgetc(fp);
    }
    printf("\n");
    fclose(fp); 									/*关闭文件*/
}
