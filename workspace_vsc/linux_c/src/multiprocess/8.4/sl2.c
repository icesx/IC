#include <sys/types.h>
#include <linux/sem.h>
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
  key_t key;
  int semid, semval;
  union semun arg;

  if ((key = ftok(".", 'c')) == -1)
  {
    perror("key error!\n");
    exit(1);
  }
  /*open signal */
  if ((semid = semget(key, 1, IPC_CREAT | 0666)) == -1)
  {
    perror("semget error!\n");
    exit(1);
  }

  while (1)
  {
    if ((semval = semctl(semid, 0, GETVAL, 0)) == -1)
    {
      perror("semctl error!\n");
      exit(1);
    }
    if (semval > 0)
    {
      printf("还有 %d 个资源可以使用\n", semval);
    }
    else
    {
      printf("没有资源可以使用\n");
      break;
    }

    sleep(3);
  }
  exit(0);
}
