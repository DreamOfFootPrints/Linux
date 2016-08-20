#include"linux.h"
#include<vector>

const int size = 100;
vector<int> vec;

//这个例子仅仅是单方向的，生产者通知消费者而已,生产者是可以不停地进行生产的，消费者必须在有数据的时候才可以进行消费

//条件变量和互斥锁是黄金搭档
//这里的大部分也是单参数的，仅仅是和锁相关的时候才不是单参数的

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* Fun1(void* a)//生产者
{
	while (1)
	{
		int index = 0;
		pthread_mutex_lock(&mutex);
		vec.push_back(index);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
		index++;
	}
	return NULL;
}

void* Fun2(void* a)//消费者
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		if (vec.size() == 0)
		{
			pthread_cond_wait(&cond, &mutex);
		}
		vec.pop_back();
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}


int main()
{
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, Fun1, NULL);
	pthread_create(&tid2, NULL, Fun2, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	pthread_mutex_destory(&mutex);
	pthread_cond_destory(&cond);

	return 0;

}