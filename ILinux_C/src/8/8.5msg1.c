#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void) {
	key_t key;
	int proj_id = 1;
	int msqid;
	char message1[] = { "hello mrsoft!" };
	char message2[] = { "goodbye!" };
	struct msgbuf {
		long msgtype;
		char msgtext[1024];
	} snd, rcv;
	key = ftok(".", proj_id);
	if (key == -1) {
		perror("create key error!");
		return 1;
	}
	if ((msqid = msgget(key, IPC_CREAT | 0666)) == -1) {
		printf("magget error!\n");
		exit(1);
	}
	snd.msgtype = 1;
	sprintf(snd.msgtext, message1);
	if (msgsnd(msqid, (struct msgbuf *) &snd, sizeof(message1) + 1, 0) == -1) {
		printf("msgsnd error!\n");
		exit(1);
	}
	snd.msgtype = 2;
	sprintf(snd.msgtext, "%s", message2);
	if (msgsnd(msqid, (struct msgbuf *) &snd, sizeof(message2) + 1, 0) == -1) {
		printf("msgrcv error!\n");
		exit(1);
	}
	if (msgrcv(msqid, (struct msgbuf *) &rcv, 80, 1, IPC_NOWAIT) == -1) {
		printf("msgrcv error!\n");
		exit(1);
	}
	printf("the received message:%s.\n", rcv.msgtext);
//msgctl(msgid,IPC_RMID,0);
	system("ipcs -q");
	exit(0);
}
