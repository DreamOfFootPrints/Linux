#include"linux.h"


void* Fun(void* a)
{
	return a;
}


int main()
{
	pthread_t tid;

	pthread_create(&tid, NULL, Fun, NULL);
	void* status=NULL;
	pthread_join(tid, &status);

}