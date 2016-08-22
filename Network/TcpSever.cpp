#include"linux.h"

int Start(const char* _ip, const int _port)
{
	int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_sock <= 0)
	{
		perror("socket");
		exit(1);
	}
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = inet_addr(_ip);
	local.sin_port = htons(_port);//注意这里也是主机->网络
	if (bind(listen_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
	{
		printf("bind");
		exit(2);
	}
	if (listen(listen_sock, 5) < 0)
	{
		printf("listen");
		exit(3);
	}

	return listen_sock;
}











int main(int argc,char* argv[])
{
	int listen_sock;
	int done = 0;
	if (argc != 3)
	{
		printf("%s [ip][port]", argv[0]);
		return;
	}
	listen_sock = Start(argv[1], atoi(argv[2]));
	while (1)
	{
		struct sockaddr_in client;
		int new_fd = accept(listen_sock, (struct sockaddr*)&client, sizeof(client));
		if (new_fd < 0)
		{
			perror("accept");
			continue;
		}
		char buf[1024];
		while (1)
		{
			memset(buf, 0, sizeof(buf));
			ssize_t len = read(new_fd, buf, sizeof(buf) - 1);
			if (len > 0)
			{
				buf[len] = '\0';
				printf("client:%s", buf);
			}
		}
	}
	close(listen_sock);
	return 0;
}