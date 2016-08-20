#include"linux.h"


int main()
{
	pid_t pid = fork();
	int fd[2];
	int pip = pipe(fd);
	if (pid == -1)
	{
		perror("pipe");
		exit(2);
	}
	if (pid == -1)
	{
		perror("error");
		exit(1);
	}
	else if (pid == 0)//child
	{
		int count = 3;
		char* msg = "i am you child\n";
		while (count--)
		{
			write(fd[1], msg, sizeof(msg));
		}
		exit(3);
	}
	else
	{
		char buf[1024];
		memset(buf, 0, sizeof(buf));
		while (read(fd[0], buf, sizeof(buf)))
		{
			printf("msg:%s\n", buf);
		}
		int status;
		int error = waitpid(getpid(), &status, WNOHANG);
		if (error == -1)
		{
			perror("waitpid");
		}
		printf("child exit code is %d\n", status >> 8);
		printf("child get signal:%d\n", status&0xFF);
	}
	return 0;
}