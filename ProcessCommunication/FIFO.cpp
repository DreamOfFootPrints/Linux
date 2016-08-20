#include"linux.h"

const char* _PATH_ = "./FIFO";

int main()
{
	pid_t pid = fork();
	int error=mkfifo("./FIFO", S_IFIFO|0666);
	if (error == -1)
	{
		perror("mkfifo");
		exit(1);
	}
	
	if (pid == -1)
	{
		perror("fork");
		exit(2);
	}
	else if (pid==0)//child
	{
		int fd = 0;
		if ((fd=open("./FIFO", O_RDONLY)) != -1)
		{
			char buf[1024];
			while (read(pid, buf, sizeof(buf)))
			{
				printf("%s\n", buf);
			}
			memset(buf, 0, sizeof(buf));
		}
		
	}
	else
	{
		int fd = 0;
		if ((fd=open("./FIFO", O_WRONLY)) != -1)
		{
			char* msg = "i am you father";
			while (write(pid, msg, sizeof(msg)))
			{
				;
			}
		}
	}
	return 0;
}