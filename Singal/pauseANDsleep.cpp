#include"linux.h"

void handler(int a)
{

} 


int My_sleep(int seconds)
{
	struct sigaction act,old;
	memset(&act, 0, sizeof(act));
	act.sa_handler = handler;
	sigempty(&act.sa_mask);
	sigaction(SIGALRM, &act, &old);
	alarm(3);
	pause();
	int ret=alarm(0);
	
	sigaction(SIGALRM, &old, NULL);
	return ret;
}

int main()
{
	My_sleep(5);
	return 0;
}