#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include <time.h>
int main() {
	int shmid;
	int proj_id;
	key_t key;
	int size;
	char *addr;
	pid_t pid;
	struct shmid_ds buf;
	struct tm *time;
	key = IPC_PRIVATE;
	shmid = shmget(key, 1024, IPC_CREAT | 0660); /*创建共享内存*/
	if (shmid == -1) {
		perror("创建共享内存失败!");
		return 1;
	}
	addr = (char*) shmat(shmid, NULL, 0);
	if (addr == (char *) (-1)) {
		perror("不能附加到进程!");
		return 1;
	}
	printf("共享内存地址:%x\n", addr);
	strcpy(addr, "欢迎来到明日科技!");
	pid = fork();
	if (pid == -1) {
		perror("错误!!!!");
		return 1;
	} else if (pid == 0) {
		printf("子进程中获取的字符串是' %s'\n", addr);
		_exit(0);
	} else {
		wait(NULL);
		printf("父进程中获取的字符串是 '%s'\n", addr);
		if (shmdt(addr) == -1) {
			perror("释放共享内存失败!");
			return 1;
		}
		if (shmctl(shmid, IPC_STAT, &buf) == -1) {
			perror("失败!");
			return 1;
		}
		printf("共享内存区域字节大小:%d\n", buf.shm_segsz);
		printf("创建该共享内存的进程ID:%d\n", buf.shm_cpid);
		printf("最近一次调用shmop函数的进程ID:%d\n", buf.shm_lpid);
		printf("使用该共享内存的进程数%ld:\n", buf.shm_nattch);
		printf("最近一次附加操作的时间:%s", ctime(&buf.shm_atime));
		printf("最近一次分离操作的时间:%s", ctime(&buf.shm_dtime));
		printf("最近一次改变的时间:%s", ctime(&buf.shm_ctime));
		if (shmctl(shmid, IPC_RMID, NULL) == -1) {
			perror("失败!");
			return 1;
		}
	}
	return 0;
}

