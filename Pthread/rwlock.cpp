#include"linux.h"
#include<string>

string str;
pthread_rwlock_t rwlock;

void* Fun1(void* a)
{
	while (1)
	{
		pthread_rwlock_wrlock(&rwlock);
		str.clear();
		str += "123456";
		pthread_rwlock_unlock(&rwlock);
	}
	return NULL;
}

void* Fun2(void* b)
{
	while (1)
	{
		pthread_rwlock_rdlock(&rwlock);
		cout << str << endl;
		pthread_rwlock_unlock(&rwlock);
	}
	return NULL;
}


int main()
{
	pthread_rwlock_init(&rwlock, NULL);
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, Fun1, NULL);
	pthread_create(&tid2, NULL, Fun2, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_rwlock_destory(&rwlock);
	return 0;
}