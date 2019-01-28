#include "Socket.h"


TCPSocket::TCPSocket()
{
	my_socket = INVALID_SOCKET;
}

bool TCPSocket::InitSocketLibrary(int lower, int higver)
{
	WORD wVersion = 0;   //use to request version
	int erret = -1;
	WSADATA wsaData;     //store require version info
	
	wVersion = MAKEWORD(2, 1);  //version 2.1

	erret = WSAStartup(wVersion, &wsaData);

	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion != 2))
	{
		printf("Init Failed!");
		return FALSE;
	}
	return TRUE;

}


SOCKET TCPSocket::InitSocket(int SocketType, string strBindIp, u_short BindPort)
{
	
	SOCKET socketid = INVALID_SOCKET;
	socketid = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in sockStruct;
	memset(&sockStruct, 0, sizeof(sockStruct));
	sockStruct.sin_family = AF_INET;
	
	if(strBindIp.empty())
	{
		sockStruct.sin_addr.s_addr = INADDR_ANY;
	}
	else
	{
		sockStruct.sin_addr.s_addr = inet_addr(strBindIp.c_str());
	}
	sockStruct.sin_port = htons(BindPort);
	
	if(SocketType == SOCKETNOBIND)
	{
		if(connect(socketid, (LPSOCKADDR)&sockStruct, sizeof(sockStruct))== SOCKET_ERROR)
		{
			printf("Connect to server failed!\n");
			closesocket(socketid);
			shutdown(socketid, 2);
			socketid = INVALID_SOCKET;
		}
		my_socket = socketid;
	}
	else if(SocketType == SOCKETBIND)
	{
		if(bind(socketid,(LPSOCKADDR)&sockStruct, sizeof(sockStruct)) == SOCKET_ERROR)
		{
			printf("Bound failed!\n");
			closesocket(socketid);
			socketid = INVALID_SOCKET;	
		}
		else
		{
			if(listen(socketid, SOMAXCONN) == SOCKET_ERROR)
			{
				printf("Listen function failed!\n");
				closesocket(socketid);
				socketid = INVALID_SOCKET;
			}
		}
		my_socket = socketid;
	}
	return socketid;
	
}

SOCKET TCPSocket::myAccept(SOCKET s, struct sockaddr* addr, int* addrlen)
{
	SOCKET accpsocket = INVALID_SOCKET;
	accpsocket = accept(s, addr, addrlen);
	return accpsocket;
}

void TCPSocket::mysend(SOCKET s, const char *buf, int len, int flag)
{
	send(s,buf,len, flag);
	
}




void TCPSocket::myrecv(SOCKET s,  char *buf, int len, int flag)
{
	recv(s, buf, len, flag);
}




