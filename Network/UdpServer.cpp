#include"linux.h"


int main(int argc,char* argv[])
{
	if (argc != 3)
	{
		printf("%s [ip][port]", argv[0]);
		exit(1);
	}

	int server_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if (server_socket ==-1)
	{
		perror("socket");
		exit(2);
	}
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = inet_addr(argv[1]);
	local.sin_port = htons(atoi(argv[2]));
	if (bind(server_socket, (struct sockaddr*)&local, sizeof(local) < 0))
	{
		perror("bind");
		exit(3);
	}

	char buf[1024];
	struct sockaddr_in remote;
	while (1)
	{
		memset(buf, 0, sizeof(buf));
		ssize_t len = recvfrom(server_socket, buf, sizeof(buf), 0, (struct sockaddr*)&remote, &sizeof(remote));
		printf("client %s", buf);
	}
	close(server_socket);
	return 0;

}