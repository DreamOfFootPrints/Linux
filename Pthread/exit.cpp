#include"linux.h"


void* Fun(void* a)
{
	pthread_self();
	*(int*)a = 0;
	//pthread_exit(a);//��ֹ�Լ�
	//return NULL;//���Ҳ�ǿ��Ե�
}


int main()
{
	pthread_t tid;
	int ret = 0;
	int err = pthread_create(&tid, NULL, Fun,&ret);
	if (err != 0)
	{
		printf("%s", strerror(err));
		//_exit(1);//ֱ�ӵ��½��̵Ĺر�
	}
	pthread_cancel(tid);//��ֹ�߳��е���������
	return 0;

}