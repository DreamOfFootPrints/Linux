#include"linux.h"


void* fun1(void* a)
{
	pthread_t tid = pthread_self();
	printf("%d", tid);
	return NULL;
}


int main()
{
	pthread_t tid = 0;
	pthread_create(&tid, NULL, fun1,NULL);
	return 0;
}