#include <sys/types.h>
#include <linux/sem.h>
#include <stdlib.h>
#include <stdio.h>
#define RESOURCE 4

int main(void)
{
  key_t key;
  int semid;
  struct sembuf sbuf = {0, -1, IPC_NOWAIT};
  union semun arg;

  if ((key = ftok(".", 'c')) == -1)
  {
    perror("ftok error!\n");
    exit(1);
  }

  if ((semid = semget(key, 1, IPC_CREAT | 0666)) == -1)
  {
    perror("semget error!\n");
    exit(1);
  }

  arg.val = RESOURCE;
  printf("可使用资源共有 %d 个\n", arg.val);
  if (semctl(semid, 0, SETVAL, arg) == -1)
  {
    perror("semctl error!\n");
    exit(1);
  }

  while (1)
  {
    if (semop(semid, &sbuf, 1) == -1)
    {
      perror("semop error!\n");
      exit(1);
    }
    sleep(3);
  }
  semctl(semid, 0, IPC_RMID, 0);
  exit(0);
}
