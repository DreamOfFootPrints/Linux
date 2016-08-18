#include"linux.h"

int main()
{
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("error");
		exit(0);
	}
	else if (pid == 0)//child
	{
		int i = 3;
		while (i--)
		{
			printf("i am a child,  %d\n,",i);
		}
		sleep(3);
	}
	else//father
	{
		int status=0;
		pid_t wait_pid = wait(&status);
		if (wait_pid == -1)
		{
			perror("wait:");
			return -2;
		}
		else
		{
			printf("child get child:%d", status & 0xFF);
			printf("child exit code is:%d", status >> 8);
		}
	}
	return 0;
}