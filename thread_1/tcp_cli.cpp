/*   ��    �������ڷ�װ��TcpSocketʵ��tcp�ͻ��˳���
*       1. �����׽���
*       2. Ϊ�׽��ְ󶨵�ַ��Ϣ�����Ƽ��û��ֶ��󶨣�
*       3. �����˷�����������
*       while(1){
*           4. ��������
*           5. ��������
*       }
*       6. �ر��׽���
================================================================*/

#include <signal.h>
#include "tcpsocket.hpp"

void sigcb(int signo) {
	printf("connection closed\n");
}
int main(int argc, char *argv[])
{
	if (argc != 3) {
		std::cout << "./tcp_cli 192.168.122.132 9000\n";
		return -1;
	}
	std::string ip = argv[1];
	uint16_t port = atoi(argv[2]);

	signal(SIGPIPE, sigcb);

	TcpSocket sock;

	CHECK_RET(sock.Socket());
	CHECK_RET(sock.Connect(ip, port));

	while (1) {
		std::string buf;
		std::cout << "client say:";
		fflush(stdout);
		std::cin >> buf;
		sock.Send(buf);
	}
	sock.Close();
	return 0;
}
