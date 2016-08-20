#include"linux.h"


void handler(int a)
{

}


int my_sleep(int second)
{
	struct sigaction  act, old;
	sigset_t mask;
	act.sa_handler = handler;
	sigempty(&mask);
	sigaddset(&mask, SIGALRM);
	sigaction(SIGALRM, &act, &old);
	alarm(second);
	sigsuspend(&mask);
	int ret = alarm(0);
	sigaction(SIGALRM, &old, NULL);
	return ret;
}

int main()
{
	my_sleep(5);
	return 0;
}
