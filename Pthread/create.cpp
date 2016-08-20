#include"linux.h"


void* Fun(void* a)
{
	printf("%d", pthread_self());
	return NULL;
}

int main()
{
	pthread_t tid;
	int err = pthread_create(&tid, NULL, Fun, NULL);
	if (err != 0)
	{
		printf("%s", strerror(err));
		exit(1);
	}
	return 0;
}