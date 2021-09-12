#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
struct dirent *dir_list(char *file)
{
    DIR *dir;
    struct dirent *ptr;
    int i;
    dir = opendir(file);                 /*打开的目录文件*/
    while ((ptr = readdir(dir)) != NULL) /*读取该目录文件中的数据*/
    {
        printf("d_name: %s\n", ptr->d_name); /*输出文件的名字*/
    }
    closedir(dir); /*关闭目录文件*/
    return ptr;
}
void file_cwd(char *cwd, int maxlenght)
{
    if (getcwd(cwd, maxlenght) == NULL) /*获取当前工作目录*/
    {
        perror("getcwd failed!");
        return;
    }
}

int file_link(char *oldpath, char *newpath)
{
    if (link(oldpath, newpath) == -1) /*创建一个硬联接*/
    {
        perror("create hard link failed!");
        return 1;
    }
    return 0;
}
int file_unlink(char *newpath)
{
    if (unlink(newpath) < 0) /*删除硬链接文件*/
    {
        perror("unlink error!");
        return 1;
    }
    printf("file unlink!\n");
    return 0;
}
struct stat *file_stat(char *file)
{
    struct stat *buf;
    stat(file, buf);
    printf("file %s size=%ld", file, buf->st_size);     /*输出文件大小*/
    printf("file %s,owner UID=%d", file, buf->st_uid); /*输出文件UID*/
    return buf;
}
int file_mkdir(char *dir)
{
    if (mkdir(dir, 0700) == -1) /*调用创建新目录的函数*/
    {
        perror("create failed!");
        return 1;
    }
    printf("create hello successful!\n");
    return 0;
}
int file_rmdir(char *dir)
{
    if (rmdir(dir) == -1)
    {
        perror("failed!");
        return 1;
    }
    printf("remove successful!\n");
    return 0;
}
