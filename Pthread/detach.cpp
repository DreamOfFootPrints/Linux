#include"linux.h"


//detachҲ���ǲ��ȴ�ֱ�ӻ�����Դ

void* Fun(void* a)
{
	return NULL;
}


int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, Fun, NULL);
	int err=pthread_detach(tid);
	if (err != 0)
	{
		printf("%s", strerror(err));
		_exit(1);
	}

	return 0;
}