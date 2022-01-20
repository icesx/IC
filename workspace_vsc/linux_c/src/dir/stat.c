#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
main()
{
    struct stat buf;
    stat("new.c", &buf);                             /*获取new.c文件信息，存放在buf中*/
    printf("new.c file size=%d\n", buf.st_size);     /*输出文件大小*/
    printf("new.c file owner UID=%d\n", buf.st_uid); /*输出文件UID*/
}
