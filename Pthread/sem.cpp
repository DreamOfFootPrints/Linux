#include"linux.h"

int arr[1024];
const int size = 1024;
sem_t space;
sem_t data;

//没有锁的生产者和消费者模型

void* Fun1(void* a)//消费者
{
	int index = 0;
	while (1)
	{
		sem_wait(&data);
		arr[index++] = 0;
		if (index == size)
			index %= size;
		sem_post(&space);
	}
	return NULL;
}

void* Fun2(void* a)//生产者
{
	int index = 0;
	while (1)
	{
		sem_wait(&space);
		arr[index++] = rand() % 1024;
		if (index == size)
			index %= size;
		sem_post(&data);
	}
}

int main()
{
	sem_init(&space, 0, size);
	sem_init(&data, 0, 0);

	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, Fun1, NULL);
	pthread_create(&tid2, NULL, Fun2, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	sem_destory(&data);
	sem_destory(&space);

	return 0;
}