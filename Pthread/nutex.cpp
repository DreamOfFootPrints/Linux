#include"linux.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//必须是全局的
//pthread_mutex_init(&mutex, NULL);//动态的分配的时候，必须这样进行初始化
//都是单参数，并且传入的都是指针，所以非常的好记



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

