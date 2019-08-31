/*   描    述：这个demo封装一个select类，
*       向外界提供更加简单的select监控接口
*       //将用户关心socket描述符添加到监控集合中
*       //从监控集合中移除不再关心的socket描述符
*       //开始监控,并且返回向用户返回就绪的socket
================================================================*/
#include <vector>
#include <sys/select.h>
#include "tcpsocket.hpp"

class Select
{
public:
	Select() :_max_fd(-1) {
		//void FD_ZERO(fd_set *set);  清空描述符集合
		FD_ZERO(&_rfds);
	}
	bool Add(TcpSocket &sock) {
		int fd = sock.GetFd();
		//void FD_SET(int fd, fd_set *set)
		//向set描述符集合中添加fd描述符
		FD_SET(fd, &_rfds);
		_max_fd = _max_fd > fd ? _max_fd : fd;
		return true;
	}
	bool Del(TcpSocket &sock) {
		int fd = sock.GetFd();
		//void FD_CLR(int fd, fd_set *set);
		//从set描述符集合中移除fd描述符
		FD_CLR(fd, &_rfds);
		for (int i = _max_fd; i >= 0; i--) {
			//int  FD_ISSET(int fd, fd_set *set);
			//判断fd描述符是否还在set集合中
			if (FD_ISSET(i, &_rfds)) {
				_max_fd = i;
				break;
			}
		}
		return true;
	}
	bool Wait(std::vector<TcpSocket> &list, int timeout_sec = 3) {
		struct timeval tv;
		tv.tv_sec = timeout_sec;
		tv.tv_usec = 0;
		fd_set set = _rfds;
		int ret = select(_max_fd + 1, &set, NULL, NULL, &tv);
		if (ret < 0) {
			perror("select error");
			return false;
		}
		else if (ret == 0) {
			std::cout << "select wait timeout\n";
			return false;
		}
		for (int i = 0; i <= _max_fd; i++) {
			if (FD_ISSET(i, &set)) {
				TcpSocket sock;
				sock.SetFd(i);
				list.push_back(sock);
			}
		}
		return true;
	}
private:
	fd_set _rfds;
	int _max_fd;
};

int main()
{
	TcpSocket sock;
	CHECK_RET(sock.Socket());
	CHECK_RET(sock.Bind("192.168.122.132", 9000));
	CHECK_RET(sock.Listen());

	Select s;
	s.Add(sock);
	while (1) {
		std::vector<TcpSocket> list;
		if (s.Wait(list) == false) {
			continue;
		}
		for (int i = 0; i < list.size(); i++) {
			if (list[i].GetFd() == sock.GetFd()) {
				TcpSocket clisock;
				std::string cli_ip;
				uint16_t cli_port;
				if (sock.Accept(clisock, cli_ip, cli_port) == false) {
					continue;
				}
				s.Add(clisock);
			}
			else {
				std::string buf;
				if (list[i].Recv(buf) == false) {
					s.Del(list[i]);
					list[i].Close();
					continue;
				}
				std::cout << "client say: " << buf << "\n";
			}
		}
	}
	sock.Close();
	return 0;
}
