
#include <stdio.h>
#include <signal.h>
#include <stdarg.h>
void sigint(int sig);
void sigcont(int sig);
int main(void)
{
    char a[100];
    if (signal(SIGINT, &sigint) == SIG_ERR) //修改SIGINT信号的处理方法为sigint()函数
    {
        perror("sigint signal error!");
    }
    if (signal(SIGCONT, &sigcont) == SIG_ERR) //修改SIGCONT信号的处理方法为sigcont()函数
    {
        perror("sigcont error!");
    }
    if (signal(SIGQUIT, SIG_IGN)) //修改SIGQUIT信号的处理方法为SIG_IGN
    {
        perror("sigquit error!");
    }
    printf("current process is: %d\n\n", getpid()); //获取当前进程的ID

    while (1)
    {
        printf("input a:");
        fgets(a, sizeof(a), stdin);        //获取键盘输入的字符串
        if (strcmp(a, "terminate\n") == 0) //比较字符串a与terminate字符
        {
            raise(SIGINT); //若两个字符串相同，则将SIGINT信号发送给当前进程
        }
        else if (strcmp(a, "continue\n") == 0)
        {
            raise(SIGCONT); //获取的字符串若与比较字符串相同，则产生SIGCONT信号给当前进程
        }
        else if (strcmp(a, "quit\n") == 0)
        {
            raise(SIGQUIT);
        }
        else if (strcmp(a, "game over\n") == 0)
        {
            raise(SIGTSTP);
        }
        else
        {
            printf("your input is:%s\n\n", a);
        }
    }
    return 0;
}
void sigint(int sig) //SIGINT信号的新的处理方法
{
    printf("SIGINT signal %d.;\n", sig);
}
void sigcont(int sig) //SIGCONT信号的新的处理方法
{
    printf("SIGCONT signal %d.;\n", sig);
}
