#include"linux.h"



int main()
{
	int ret = alarm(10);
	if (ret == -1)
	{
		perror("alarm");
		exit(1);
	}
	return 0;
}