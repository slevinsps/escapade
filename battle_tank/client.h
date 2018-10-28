#ifndef CLIENT_H
#define CLIENT_H



// Получаем с сервера
#include "scene.h"

// Получаем с сервера
#include "lobby.h"

// Отправляем на сервер
#include "user_control.h"

// В опциях проекта, в разделе Linker, в пункте Additional Dependancies укажите Ws2_32.lib

// http://it.mmcs.sfedu.ru/wiki/Введение_в_сетевое_программирование

class UPD_client
{
public:
    UPD_client();

    int init();

    void send(int sd, const std::string &msg);

};

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>



int init() {
    WSADATA wsaData;
    SOCKET SendRecvSocket;  // сокет для приема и передачи
    sockaddr_in ServerAddr;  // это будет адрес сервера и клиентов
    int err, maxlen = 512;  // код ошибки, размер буферов и размер структуры адреса
    char* recvbuf=new char[maxlen];  // буфер приема
    char* query=new char[maxlen];  // буфер отправки

    // Initialize Winsock
    WSAStartup(MAKEWORD(2,2), &wsaData);

    // Create a SOCKET for connecting to server
    SendRecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    ServerAddr.sin_family=AF_INET;
    ServerAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    ServerAddr.sin_port=htons(12345);

    _snprintf_s(query,maxlen,maxlen,"CALC * 12 6\n");
    // отправляем запрос на сервер
    sendto(SendRecvSocket,query, strlen(query), 0, (sockaddr *)&ServerAddr,sizeof(ServerAddr));
    printf("Sent: %s\n", query);

    // получаем результат
    err = recvfrom(SendRecvSocket,recvbuf,maxlen,0,0,0);
    if (err > 0) {
        recvbuf[err]=0;
        printf("Result: %s\n", (char* )recvbuf);
    }
    else {
        printf("recv failed: %d\n", WSAGetLastError());
        closesocket(SendRecvSocket);
        WSACleanup();
        return 1;
    }

    closesocket(SendRecvSocket);
    return 0;
}

#endif // CLIENT_H
