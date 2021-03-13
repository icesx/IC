﻿#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define FIFO "fifo4"
int main(void)
{
    int fd;
    int pid;
    char r_msg[BUFSIZ];
    if ((pid = mkfifo(FIFO, 0777)) == -1)
    {
        perror("create fifo channel failed!");
        return 1;
    }
    else
        printf("create success!\n");
    fd = open(FIFO, O_RDWR);
    if (fd == -1)
    {
        perror("cannot open the FIFO");
        return 1;
    }
    if (write(fd, "hello world", 12) == -1)
    {
        perror("write data error!");
        return 1;
    }
    else
        printf("write data success!\n");

    if (read(fd, r_msg, BUFSIZ) == -1)
    {
        perror("read error!");
        return 1;
    }
    else
        printf("the receive data is %s!\n", r_msg);
    close(fd);

    return 0;
}
