#pragma once
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <string>
using namespace std;

#define SOCKETBIND 1
#define SOCKETNOBIND 2
#define SOCKET_TIMEOUT -100



class CMYTcpTran
{
public:
	CMYTcpTran();
	~CMYTcpTran();

	static BOOL  InitSocketLibrary(int lower, int higver);

	SOCKET InitSocket(
		int SocketType, string strBindIp, u_short BindPort
	);
	SOCKET myaccept(
		SOCKET s, struct sockaddr* addr, int* addrlen
	);
	int mysend(SOCKET sock, const char *buf, int len, int flag, int overtime);
	int myrecv(SOCKET sock, char *buf, int len, int flag, int overtime, char* EndMark, BOOL soonflag = FALSE);
private:
	SOCKET  m_Socket;
};




CMYTcpTran::CMYTcpTran()
{
	m_Socket = INVALID_SOCKET;
}


CMYTcpTran::~CMYTcpTran()
{
}

BOOL CMYTcpTran::InitSocketLibrary(int lower, int higver)
{
	WORD wVersion = 0;   //use to request version
	int erret = -1;
	WSADATA wsaData;     //store require version info
	
	wVersion = MAKEWORD(2, 1);  //version 2.1

	erret = WSAStartup(wVersion, &wsaData);

	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion != 2))
	{
		MessageBox(NULL,L"Version error!", MB_OK);
		return FALSE;
	}

	return TRUE;
}

SOCKET CMYTcpTran::InitSocket(                                       //set up parameter and connect!!
	int SocketType, string strBindIp, u_short BindPort
) 
{
	SOCKET socketid = INVALID_SOCKET;
	socketid = socket(PF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN sockStruct;

	sockStruct.sin_family = AF_INET;


	if (strBindIp.empty())
	{
		sockStruct.sin_addr.S_un.S_addr = INADDR_ANY;  //accept any IP
	}
	else
	{
		sockStruct.sin_addr.S_un.S_addr = inet_addr(strBindIp.c_str());   //string-> char* -->u_long
	}

	sockStruct.sin_port = htons(BindPort);  //turn BindPort to network unit

	if (SocketType == SOCKETNOBIND)    //use connect() means connect client 
	{
		if (connect(socketid, (LPSOCKADDR)&sockStruct, sizeof(sockStruct)) == SOCKET_ERROR)
		{
			printf("Connect error!!");
			closesocket(socketid);
			shutdown(socketid, 2);
			socketid = INVALID_SOCKET;
		}
		m_Socket = socketid;
	}
	else if(SocketType == SOCKETBIND)  //use bind()
	{
		if (bind(socketid, (sockaddr*)&sockStruct, sizeof(sockaddr_in)) == SOCKET_ERROR)
		{
			printf("Bind error!!\n");
			closesocket(socketid);
			socketid = INVALID_SOCKET;
		}
		else
		{
			if (listen(socketid, SOMAXCONN) == SOCKET_ERROR)
			{
				printf("Listen error!!\n");
				closesocket(socketid);
				socketid = INVALID_SOCKET;
			}
		}
		m_Socket = socketid;
	}

	return socketid;    //return socketid???
}

SOCKET CMYTcpTran::myaccept(
	SOCKET s, struct sockaddr* addr, int* addrlen
)
{
	SOCKET accpsocket = INVALID_SOCKET;
	accpsocket = accept(s, addr, addrlen);
	return accpsocket;
}

int CMYTcpTran::myrecv(SOCKET sock, char *buf, int len, int flag, int overtime, char* EndMark, BOOL soonflag = FALSE)
{
	int ret;
	int nLeft = len;
	int idx = 0;
	int nCount;
	fd_set readfds;  //describe object
	struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = 500;
	DWORD s_time = GetTickCount(); //return time since the system start 

	while (nLeft > 0)
	{
		MSG msg;
		PeekMessage( &msg, NULL, 0, 0, PM_REMOVE );   
		if (msg.message == WM_QUIT)
		{
			return 0;
		}

		FD_ZERO( &readfds );    
		FD_SET(sock, &readfds); 

		if(select(0, &readfds, NULL, NULL, &timeout) == SOCKET_ERROR)
		{
			return SOCKET_ERROR;
		}

		DWORD e_time = GetTickCount();
		if (!FD_ISSET(sock, &readfds))
		{
			if (e_time - s_time > overtime * 1000)
			{
				return SO_RCVTIMEO;
			}
			else
				continue;

			ret = recv(sock, &buf[idx], nLeft, flag); //receive data

			if (soonflag == TRUE)  //imidiately return msg
			{
				return ret;
			}

			s_time = e_time;

			if (ret < 0)  // handel error
			{
				int LastError = GetLastError();
				if ((-1 == ret) && (WSAETIMEDOUT == LastError))
				{
					continue;
				}
				if ((-1 == ret) && (WSAEWOULDBLOCK == LastError))
				{
					if (nCount < 2000)
					{
						Sleep( 10 );
						nCount++;
						continue;
					}
				}
				return ret;
			}
			nCount = 0;

			nLeft -= ret;
			idx += ret;

			if (EndMark != NULL && idx > 5)
			{
				if (strstr(buf + (idx - 5), EndMark) != NULL)
				{
					break;
				}
			}

		}
	}

	return idx;
}


int CMYTcpTran::mysend(SOCKET sock, const char *buf, int len, int flag, int overtime)
{
	int ret;
	int nLeft = len;
	int idx = 0;
	fd_set readfds;
	struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = 500;

	DWORD s_time = GetTickCount();

	while (nLeft > 0)
	{
		MSG msg;
		PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
		if (msg.message == WM_QUIT)
			return 0;

		FD_ZERO(&readfds);
		FD_SET(sock, &readfds);

		int errorret = select(0, NULL, &readfds, NULL, &timeout);
		if (errorret == SOCKET_ERROR)
		{
			OutputDebugStringA("mysendEx SOCKET Error");
			return SOCKET_ERROR;
		}

		DWORD e_time = GetTickCount();
		
		if (!FD_ISSET(sock, &readfds))
		{
			if (e_time - s_time > overtime * 1000)
			{
				OutputDebugStringA("mysendEx send over time\n");
				return 0;
			}
			else
			{
				OutputDebugStringA("send FD_ISSET over time\n");
				continue;
			}
		}
		ret = send(sock, &buf[idx], nLeft, flag);

		if (ret <= 0)
		{
			return ret;
		}

		nLeft -= ret;
		idx += ret;
	}

}
