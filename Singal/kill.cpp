#include"linux.h"


int main()
{
	//int ret = kill(getpid(), 19);
	int ret=raise(19);
	if (ret == -1)
	{
		//perror("kill");
		perror("raise");
		exit(1);
	}
	abort();
	return 0;
}