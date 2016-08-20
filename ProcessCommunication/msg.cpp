#include"linux.h"

char* PATH = "./";
char PRO_ID = 1;

int main()
{
	key_t key = ftok(PATH, PRO_ID);
	if (key == -1)
	{
		perror("key:");
		exit(1);
	}
	int msgid = msgget(key, IPC_CREAT | IPC_EXCL);
	if (msgid == -1)
	{
		perror("msgid:");
		exit(2);
	}
	int pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(3);
	}
	//这个buf很特殊
	else if (pid==0)//child
	{
		struct buf
		{
			long mtype;
			char text[100];
		};
		
		struct buf buffer;
		buffer.mtype = 0;
		char* msg = "i am a chlid\n";
		memcpy(buffer.text, msg, sizeof(msg));
		
		while (msgsnd(msgid, &buffer, sizeof(msg), 0)!=-1)
		{
			; 
		}
	}
	else
	{
		char buf[1024];
		while (msgrcv(msgid, buf,sizeof(buf),0,0)!=0)
		{
			printf("%s\n", buf);
			memset(buf, 0, sizeof(buf));
		}
	}
	int error=msgctl(msgid, IPC_RMID, NULL);
	if (error == -1)
	{
		perror("msgctl");
		exit(6);
	}
	return 0;
}