#include"linux.h"
#define _PATH_ "./"
#define _PRO_ID 12


//建立的是一个信号量的集合
//信号量集关键的是PV操作
//PV操作居然都是一个函数

int main()
{
	key_t key = ftok(_PATH_, _PRO_ID);
	if (key == -1)
	{
		perror("ftok");
		exit(1);
	}
	int semid = semget(key, 1, IPC_CREAT | IPC_EXCL);
	union semun
	{
		int val;
		void* buf1;
		void* buf2;
		void* buf3;
	};
	union semun un;
	un.val = 1;

	if (-1 == semctl(semid, 0, SETVAL, &un))
	{
		perror("-1");
		exit(3);
	}
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(2);
	}
	else if (pid==0)//child
	{
		sembuf buf;
		buf.semnum = 0;
		buf.val = 1;
		buf.flag = 0;
		if (-1!=semop(semid, &buf, 1))
		{

		}
	}
	else//father
	{
		sembuf buf;
		buf.semnum = 0;
		buf.val = -1;
		buf.flag = 0;
		if (-1 != semop(semid, &buf, 1))
		{

		}
	}
	semctl(semid, 0, IPC_RMID);
	return 0;
}