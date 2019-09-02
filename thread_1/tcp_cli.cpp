/*   描    述：基于封装的TcpSocket实现tcp客户端程序
*       1. 创建套接字
*       2. 为套接字绑定地址信息（不推荐用户手动绑定）
*       3. 向服务端发起连接请求
*       while(1){
*           4. 发送数据
*           5. 接收数据
*       }
*       6. 关闭套接字
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
