#include"linux.h"


int main()
{
	pid_t pid = vfork();
	int g_val = 0;
	if (pid == -1)
	{
		perror("fork:");
		return -1;
	}
	else if (pid==0)//child
	{
		g_val++;
		exit(0);
	}
	else//father
	{
		printf("%d\n", g_val);
	}
	return 0;
}