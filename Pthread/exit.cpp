#include"linux.h"


void* Fun(void* a)
{
	pthread_self();
	*(int*)a = 0;
	//pthread_exit(a);//终止自己
	//return NULL;//这个也是可以的
}


int main()
{
	pthread_t tid;
	int ret = 0;
	int err = pthread_create(&tid, NULL, Fun,&ret);
	if (err != 0)
	{
		printf("%s", strerror(err));
		//_exit(1);//直接导致进程的关闭
	}
	pthread_cancel(tid);//终止线程中的其他进程
	return 0;

}