#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")  //�[? ws2_32.dll
int main(){
    //��l��DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //?�خM���r
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //�V�A?��?�_?�D
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //�C?�r?����0��R
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(1234);
    connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    //�����A?��?�^��?�u
    char szBuffer[MAXBYTE] = {0};
    recv(sock, szBuffer, MAXBYTE, NULL);
    //?�X�����쪺?�u
    printf("Message form server: %s\n", szBuffer);
    //??�M���r
    closesocket(sock);
    //?��ϥ� DLL
    WSACleanup();
    system("pause");
    return 0;
}
