#include"linux.h"






int main(int argc,char* argv[])
{
	if (argc != 3)
	{
		printf("%s  [ip][port]", argv[0]);
		exit(0);
	}
	int socket_client = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_client == -1)
	{
		perror("socket");
		exit(1);
	}

	struct sockaddr_in remote;//链接远端的[IP][PORT]
	remote.sin_family = AF_INET;
	remote.sin_addr.s_addr = inet_addr(argv[1]);//点分十进制到长整形之间的转换
	remote.sin_port = htons(atoi(argv[2]));//网络字节序和主机直接序之间的转换
					//但是仅仅是端口号，对于IP地址来说，是不使用这个函数的
	if (connect(socket_client, (struct sockaddr*)&remote, sizeof(remote)) == -1)
	{
		perror("connect");
		exit(2);
	}
	char buf[1024];
	while (1)
	{
		memset(buf, '\0', sizeof(buf));
		ssize_t len = read(0, buf, sizeof(buf) - 1);
		if (len > 0)
		{
			write(socket_client, buf, len);
		}
	}
	close(socket_client);
	return 0;

}