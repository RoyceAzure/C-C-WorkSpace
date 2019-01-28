#ifndef _SOCKET_H_
#define _SOCKET_H_
#include <winsock2.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#define SOCKETBIND 1
#define SOCKETNOBIND 2
#define MAX 100

using namespace std;

class TCPSocket{
	public:
		TCPSocket();
		bool InitSocketLibrary(int , int); 
		SOCKET InitSocket(int SocketType, string strBindIp, u_short BindPort);
		SOCKET myAccept(SOCKET , struct sockaddr*, int* );
		void mysend(SOCKET , const char *, int , int);
		void myrecv(SOCKET ,  char *, int , int);
		int adv_send(SOCKET sock, const char *buf, int len, int flag, int overtime);
		int adv_recv(SOCKET , char *, int, int , int , char* , BOOL soonflag = FALSE );
	private:
		SOCKET my_socket_;
	
};
#endif
