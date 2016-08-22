#include"linux.h"

int main(int argc,char* argv[])
{
	if (argc != 3)
	{
		printf("%s [ip][port]", argv[0]);
		exit(1);
	}
	int client_sock = socket(AF_INET, SOCK_DGRAM, 0);//gram克的意思
	if (client_sock == -1)
	{
		perror("socket");
		exit(2);
	}
	struct sockaddr_in remote;
	remote.sin_family = AF_INET;
	remote.sin_addr.s_addr = inet_addr(argv[1]);
	remote.sin_port = htons(atoi(argv[2]));
	char buf[1024];
	while (1)
	{
		ssize_t len = read(0, buf, sizeof(buf) - 1);
		if (len > 0)
		{
			buf[len] = '0';
		}
		len = sendto(client_sock, buf, sizeof(buf) - 1, 0, (struct addr*)&remote, sizeof(remote));
	}
	close(client_sock);
	return 0;
}