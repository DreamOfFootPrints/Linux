#include"linux.h"


int main()
{
	pid_t pid = vfork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid==0)
	{
		char* argv[5] = { "123", "345", "345",NULL };
		char* path[5] = { "PATH=/bin/bash", NULL };
		execv( "/home / chen / file", argv);
		_exit(2);//≤ª«Â¿ÌI/Oª∫¥Ê
	}
	else
	{
		int status = 0;
		pid_t wait_pid = wait(&status);
	}
	return 0;
}