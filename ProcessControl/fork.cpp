#include"linux.h"


int main()
{
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return -1;
	}
	else if (pid == 0)//child
	{
		printf("i am a child,%d",getpid());
	}
	else//father
	{
		printf("i am a father", getpid());
		sleep(1);
	}
	return 0;
}