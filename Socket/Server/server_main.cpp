#include "Socket.h"
TCPSocket::TCPSocket()
{
	my_socket_ = INVALID_SOCKET;
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
		my_socket_ = socketid;
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
		my_socket_ = socketid;
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
	scanf("%s",buf);
	send(s,buf,len, flag);
	
}






int TCPSocket::adv_recv(SOCKET sock, char *buf, int len, int flag, int overtime, char* EndMark, BOOL soonflag )
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
		PeekMessage( &msg, NULL, 0, 0, PM_REMOVE );   //receive msg from the app who calls this function, and 0 0 means get all the msg
		if (msg.message == WM_QUIT)  //receive msg == quit commend
		{
			return 0;
		}

		FD_ZERO( &readfds );    //reset
		FD_SET(sock, &readfds); 

		if(select(0, &readfds, NULL, NULL, &timeout) == SOCKET_ERROR)   
		{
			return SOCKET_ERROR;
		}

		DWORD e_time = GetTickCount();
		if (!FD_ISSET(sock, &readfds))   //manage over time
		{
			if (e_time - s_time > overtime * 1000)
			{
				printf("over time!!\n");
				return -1;
			}
			else
				continue;
		}
		else
		{
			ret = recv(sock, &buf[idx], nLeft, flag); // FD_ISSET  is true so u can receive data

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


int TCPSocket::adv_send(SOCKET sock, const char *buf, int len, int flag, int overtime)
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
			OutputDebugStringA("select() ERROR\n");
			return SOCKET_ERROR;
		}

		DWORD e_time = GetTickCount();
		
		if (!FD_ISSET(sock, &readfds))
		{
			if (e_time - s_time > overtime * 1000)
			{
				OutputDebugStringA("wait to msg over time\n");
				return 0;
			}
			else
			{
				OutputDebugStringA("wait msg\n");
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
int main()
{
	
	TCPSocket my_socket = TCPSocket();
	if(my_socket.InitSocketLibrary(2,2))
	{
		SOCKET my_listen_server = my_socket.InitSocket(1, "127.0.0.1", 20001);
		
		if(my_listen_server != INVALID_SOCKET)
		{	
		
			SOCKET client = INVALID_SOCKET;
			sockaddr_in cli_sockAddr;
			int len = sizeof(cli_sockAddr);
			memset(&cli_sockAddr, 0, sizeof(cli_sockAddr));

			while(true)
			{
				printf("Waiting for connecting......\n");
				if(client = my_socket.myAccept(my_listen_server, (SOCKADDR*)&cli_sockAddr, &len));
				{
					printf("a connection was found");
            		printf("server: got connection from %s\n", inet_ntoa(cli_sockAddr.sin_addr));
            		
            		char recvbuf[MAX] ;
            		char sendbuf[MAX]  ;
            		
		            strcpy(sendbuf, "Welcome to server Name: Rocye wang\n");
		            my_socket.adv_send(client, sendbuf, (int)strlen(sendbuf), 0, 5);
		            memset(sendbuf, 0, sizeof(sendbuf));
		            strcpy(sendbuf, "406417054");
            		my_socket.adv_send(client, sendbuf, (int)strlen(sendbuf), 0, 5);
		            
		            while(sendbuf, strstr(recvbuf, "end")==NULL)
		            {
		            	memset(recvbuf, 0, sizeof(recvbuf));
		            	int ret = my_socket.adv_recv(client, recvbuf, MAX, 0, 5, NULL, TRUE);
						printf("get %d bytes from %s\n",ret, inet_ntoa(cli_sockAddr.sin_addr));
						printf("msg: %s\n",recvbuf);
							
					}
					

				}
			}
				
		}
	}
	return 0;
}
	

