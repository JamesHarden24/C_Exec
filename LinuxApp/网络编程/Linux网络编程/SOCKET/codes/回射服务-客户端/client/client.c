
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"
#include "../server/server.h"
#include "../include/type.h"

#define ERR_EXIT(m)\
    do \
    { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


int main(int argc, const char *argv[])
{
    CHAR cSendBuf[RECV_LEN];
    CHAR cRecvBuf[RECV_LEN];
    INT iClientSock;
    struct sockaddr_in stServerAddr;

    if ((iClientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        ERR_EXIT("socket");

    memset(&stServerAddr, 0, sizeof(stServerAddr));
    stServerAddr.sin_family = AF_INET;
    stServerAddr.sin_port = htons(SERVER_PORT);
    stServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(iClientSock, (struct sockaddr *)&stServerAddr, sizeof(stServerAddr)) < 0)
        ERR_EXIT("connect");

    while (fgets(cSendBuf, sizeof(cSendBuf), stdin) != NULL)
    {
        //printf("%s\n",cSendBuf );
        memset(cRecvBuf, 0, RECV_LEN);
        write(iClientSock, cSendBuf, strlen(cSendBuf));
        read(iClientSock, cRecvBuf, sizeof(cRecvBuf));

        printf("%s\n", cRecvBuf);
        memset(cSendBuf, 0, RECV_LEN);
    }

    return 0;
}


