#include"linux.h"
#define _PATH_ "./"
#define _PRO_ID_ 3

//��������֮�󷵻ر�ʶ����
//�����Ƿ���·�����������ʱ�����ֱ��ʹ��write��read����open


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
		//��������
		char* addr = (char*)shmat(shmId, NULL, 0);//�ڶ���Ӧ���Ǿ���ĵ�ַ�����ӵ���ַ�ռ����һ��λ��
		char* buf = "i am a child\n";
		memcpy(addr, buf, sizeof(buf));
		//�Ͽ�����
		int ret = shmdt(addr);
		if (ret == -1)
		{
			perror("shmdt");
		}
	}
	else//father
	{
		//��������
		char* addr = (char*)shmat(shmId, NULL, 0);
		char buf[1024];
		memcpy(buf, addr, sizeof(addr));
		//�Ͽ�����
		int ret = shmdt(addr);
		if (ret == -1)
		{
			perror("shmdt");
		}
	}
	shmctl(shmId, IPC_RMID, NULL);
	return 0;
}

