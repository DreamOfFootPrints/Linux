#include"linux.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//������ȫ�ֵ�
//pthread_mutex_init(&mutex, NULL);//��̬�ķ����ʱ�򣬱����������г�ʼ��
//���ǵ����������Ҵ���Ķ���ָ�룬���Էǳ��ĺü�



void* Fun1(void* a)
{
	sleep(1);
	while (1)
	{
		char* msg = "A";
		pthread_mutex_lock(&mutex);
		printf("%s\n", msg);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}


void* Fun2(void* a)
{
	while (1)
	{
		char* msg = "B";
		pthread_mutex_lock(&mutex);
		printf("%s\n", msg);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}


int main()
{
	pthread_t tid1,tid2;
	pthread_create(&tid1, NULL, Fun1, NULL);
	pthread_create(&tid2, NULL, Fun1, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destory(&mutex);
	return 0;
}

