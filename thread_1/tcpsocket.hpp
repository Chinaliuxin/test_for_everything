/**     1. �����׽���           Socket()
*       2. �󶨵�ַ��Ϣ         Bind(std::string &ip, uint16_t port)
*       3. ����˿�ʼ����       Listen(int backlog = 5)
*       4. �����ȡ��������ӵĿͻ�����socket
*          Accept(TcpSocket &clisock, std::string &cli_ip, uint16_t port)
*       5. ��������             Recv(std::string &buf)
*       6. ��������             Send(std::string &buf)
*       7. �ر��׽���           Close()
*       3. �ͻ��������˷�����������
*           Connect(std::string &srv_ip, uint16_t srv_port);
================================================================*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define CHECK_RET(q) if((q) == false){return -1;}

class TcpSocket
{
public:
	TcpSocket() {
	}
	~TcpSocket() {
	}
	bool Socket() {
		_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (_sockfd < 0) {
			perror("socket error");
			return false;
		}
		int opt = 1;
		setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR,
			(void*)&opt, sizeof(int));
		return true;
	}
	void SetNonBlock() {
		//int fcntl(int fd, int cmd, ... /* arg */ );
		int flag = fcntl(_sockfd, F_GETFL, 0);
		fcntl(_sockfd, F_SETFL, flag | O_NONBLOCK);
	}
	bool Bind(const std::string &ip, const uint16_t port) {
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip.c_str());

		socklen_t len = sizeof(struct sockaddr_in);
		int ret = bind(_sockfd, (struct sockaddr*)&addr, len);
		if (ret < 0) {
			perror("bind error");
			return false;
		}
		return true;
	}
	bool Listen(int backlog = 5) {
		//int listen(int sockfd, int backlog)
		//  sockfd: �׽���������
		//  backlog����󲢷�������-�����ں�����������Ӷ��нڵ����
		//  backlog�����Ĳ��Ƿ�����ܽ��յĿͻ����������
		int ret = listen(_sockfd, backlog);
		if (ret < 0) {
			perror("listen error");
			return false;
		}
		return true;
	}
	bool Accept(TcpSocket &cli, std::string &cliip, uint16_t &port) {
		//int accept(int sockfd, struct sockaddr *addr, 
		//socklen_t *addrlen);
		//sockfd:   �׽���������
		//addr��    �½����ӵĿͻ��˵�ַ��Ϣ
		//addrlen�� �½��ͻ��˵ĵ�ַ��Ϣ����
		//����ֵ�������½��ͻ���socket��������
		struct sockaddr_in addr;
		socklen_t len = sizeof(struct sockaddr_in);
		int sockfd = accept(_sockfd, (struct sockaddr*)&addr, &len);
		if (sockfd < 0) {
			perror("accept error");
			return false;
		}
		cli.SetFd(sockfd);
		cliip = inet_ntoa(addr.sin_addr);
		port = ntohs(addr.sin_port);
		return true;
	}
	void SetFd(int sockfd) {
		_sockfd = sockfd;
	}
	int GetFd() {
		return _sockfd;
	}
	bool Connect(std::string &srv_ip, uint16_t srv_port) {
		//int connect(int sockfd, const struct sockaddr *addr,
		//socklen_t addrlen);
		//sockfd:   �׽���������
		//addr��    ����˵�ַ��Ϣ
		//addrlen�� ��ַ��Ϣ����
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(srv_port);
		addr.sin_addr.s_addr = inet_addr(srv_ip.c_str());
		socklen_t len = sizeof(struct sockaddr_in);

		int ret = connect(_sockfd, (struct sockaddr*)&addr, len);
		if (ret < 0) {
			perror("connect error");
			return false;
		}
		return true;
	}
	bool Recv(std::string &buf) {
		//ssize_t recv(int sockfd, void *buf, size_t len, int flags)
		//sockfd:   �����Ϊ�¿ͻ����½���socket������
		//flags��   0-Ĭ���������գ�û�����ݾ�һֱ�ȴ�
		//      MSG_PEEK    �������ݣ��������ݲ����ӽ��ջ������Ƴ�
		//      ������̽�������ݽ���
		//����ֵ��ʵ�ʽ����ֽڳ��ȣ�������-1�������ӶϿ��򷵻�0
		//recvĬ���������ģ���ζ��û��������һֱ�ȣ����᷵��0��
		//����0ֻ��һ��������������ӶϿ��������ټ���ͨ����
		while (1) {
			char tmp[5];
			int ret = recv(_sockfd, tmp, 5, 0);
			if (ret < 0) {
				if (errno == EAGAIN) {
					break;
				}
				perror("recv error");
				return false;
			}
			else if (ret == 0) {
				printf("peer shutdown\n");
				return false;
			}
			tmp[ret] = '\0';
			buf += tmp;
		}
		return true;
	}
	bool Send(std::string &buf) {
		//ssize_t send(int sockfd, void *buf, size_t len, int flags)
		int ret = send(_sockfd, buf.c_str(), buf.size(), 0);
		if (ret < 0) {
			perror("send error");
			return false;
		}
		return true;
	}
	bool Close() {
		close(_sockfd);
		return true;
	}
private:
	int _sockfd;
};
