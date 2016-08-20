#include"linux.h"
#define _PATH_ "./"
#define _PRO_ID_ 3

//建立链接之后返回标识符，
//但不是返回路径，所以这个时候就是直接使用write和read不是open


int main()
{
	key_t key = ftok(_PATH_, _PRO_ID_);
	if (key == -1)
	{
		perror("key");
		exit(1);
	}
	int shmId = shmget(key, 1024, IPC_CREAT | IPC_EXCL);
	if (shmId == -1)
	{
		perror("shmget");
		exit(2);
	}
	int pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(3);
	}
	else if (pid == 0)//child
	{
		//建立链接
		char* addr = (char*)shmat(shmId, NULL, 0);//第二个应该是具体的地址，连接到地址空间的那一个位置
		char* buf = "i am a child\n";
		memcpy(addr, buf, sizeof(buf));
		//断开链接
		int ret = shmdt(addr);
		if (ret == -1)
		{
			perror("shmdt");
		}
	}
	else//father
	{
		//建立链接
		char* addr = (char*)shmat(shmId, NULL, 0);
		char buf[1024];
		memcpy(buf, addr, sizeof(addr));
		//断开链接
		int ret = shmdt(addr);
		if (ret == -1)
		{
			perror("shmdt");
		}
	}
	shmctl(shmId, IPC_RMID, NULL);
	return 0;
}

