/*   描    述：这个demo完成epoll接口的基本封装
*       bool Init()
*       bool Add(TcpSocket &sock)
*       bool Del(TcpSocket &sock)
*       bool Wait(std::vector<TcpSocket> &list, int timeout_msec)
================================================================*/
#include <iostream>
#include <vector>
#include <sys/epoll.h>
#include "tcpsocket.hpp"

#define MAX_EVENTS 10

class Epoll
{
public:
	bool Init() {
		//int epoll_create(int size);
		_epfd = epoll_create(1);
		if (_epfd < 0) {
			perror("epoll create error");
			return false;
		}
		return true;
	}
	bool Add(TcpSocket &sock) {
		//int epoll_ctl(int epfd,int op,int fd,epoll_event *event);
		//op:   EPOLL_CTL_ADD/EPOLL_CTL_DEL/EPOLL_CTL_MOD
		int fd = sock.GetFd();
		struct epoll_event ev;
		ev.data.fd = fd;
		ev.events = EPOLLIN | EPOLLET;
		int ret = epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &ev);
		if (ret < 0) {
			perror("epoll add error");
			return false;
		}
		return true;
	}
	bool Del(TcpSocket &sock) {
		int fd = sock.GetFd();
		int ret = epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, NULL);
		if (ret < 0) {
			perror("epoll del error");
			return false;
		}
		return true;
	}
	bool Wait(std::vector<TcpSocket> &list, int timeout_msec = 3000) {
		//int epoll_wait(int epfd, struct epoll_event *events,
		//  int maxevents, int timeout);
		struct epoll_event evs[MAX_EVENTS];
		int nfds = epoll_wait(_epfd, evs, MAX_EVENTS, timeout_msec);
		if (nfds < 0) {
			perror("epoll wait error");
			return false;
		}
		else if (nfds == 0) {
			std::cerr << "epoll wait timeout\n";
			return false;
		}
		for (int i = 0; i < nfds; i++) {
			TcpSocket sock;
			sock.SetFd(evs[i].data.fd);
			list.push_back(sock);
		}
		return true;
	}
private:
	int _epfd;
};

int main()
{
	TcpSocket lst_sock;
	CHECK_RET(lst_sock.Socket());
	lst_sock.SetNonBlock();
	CHECK_RET(lst_sock.Bind("0.0.0.0", 9000));
	CHECK_RET(lst_sock.Listen());

	Epoll epoll;
	CHECK_RET(epoll.Init());
	CHECK_RET(epoll.Add(lst_sock));

	while (1) {
		std::vector<TcpSocket> list;
		bool ret = epoll.Wait(list);
		if (ret == false) {
			continue;
		}
		for (int i = 0; i < list.size(); i++) {
			if (lst_sock.GetFd() == list[i].GetFd()) {
				TcpSocket cli_sock;
				std::string cli_ip;
				uint16_t cli_port;
				ret = lst_sock.Accept(cli_sock, cli_ip, cli_port);
				if (ret == false) {
					continue;
				}
				cli_sock.SetNonBlock();
				epoll.Add(cli_sock);
			}
			else {
				std::string buf;
				ret = list[i].Recv(buf);
				if (ret == false) {
					epoll.Del(list[i]);
					list[i].Close();
					continue;
				}
				std::cout << "client say:" << buf << std::endl;
			}
		}

	}
	lst_sock.Close();
	return 0;
}
