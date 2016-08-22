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

	struct sockaddr_in remote;//����Զ�˵�[IP][PORT]
	remote.sin_family = AF_INET;
	remote.sin_addr.s_addr = inet_addr(argv[1]);//���ʮ���Ƶ�������֮���ת��
	remote.sin_port = htons(atoi(argv[2]));//�����ֽ��������ֱ����֮���ת��
					//���ǽ����Ƕ˿ںţ�����IP��ַ��˵���ǲ�ʹ�����������
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