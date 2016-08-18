#include"linux.h"


int main()
{
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork:");
		return -1;
	}
	else if (pid == 0)//child
	{
		int count = 3;
		while (count--)
		{
			printf("chlid:%d\n", count);
		}
		exit(2);
	}
	else
	{
		int status = 0;
		pid_t wait_pid = waitpid(-1, &status, WNOHANG);
		if (wait_pid == -1)
		{
			perror("waitpid:");
		}
		else
		{
			printf("child get signal is %d", status & 0xFF);
			printf("child exit coid is %d", status >> 8);
		}
	}
	return 0;
}