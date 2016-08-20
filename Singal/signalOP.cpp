#include"linux.h"


void handler(int a)
{
	printf("%d\n", a);
	printf("i am a big bug\n");
}


int main()
{
	int pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid==0)//child
	{
		kill(getppid(), 2);
	}
	else//father
	{
		sigset_t new1;
		sigset_t old;
		sigempty(&new1), sigempty(&old);
		//sigefillset(new1);
		sigaddset(&new1, 2);
		sigaddset(&new1, 2);
		if (sigismember(&new1, 19))
		{
			printf("no 19 signal");
		}
		sigprocmask(SIG_SETMASK, &new1, &old);
		sleep(2);
		sigset_t tmp;
		sigpending(&tmp);
		struct sigaction new_act;
		new_act.sa_handler = &handler;
		new_act.sa_mask = new1;
	}
	return 0;
}