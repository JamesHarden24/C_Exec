

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../include/type.h"
#include "server.h"

#define ERR_EXIT(m)\
    do \
    { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    CHAR cRecvBuf[RECV_LEN];
    INT iListenFd;
    INT iConFd;
    INT iRet;
    socklen_t tClientLen;
    struct sockaddr_in stServerAddr;
    struct sockaddr_in stClientAddr;

    if ((iListenFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        ERR_EXIT("socket");

    memset(&stServerAddr, 0, sizeof(stServerAddr));
    stServerAddr.sin_family = AF_INET;
    stServerAddr.sin_port = htons(SERVER_PORT);
    //inet_aton("127.0.0.1", &stServerAddr.sin_addr);   
    stServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //stServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if ((bind(iListenFd, (struct sockaddr *)&stServerAddr, sizeof(stServerAddr))) < 0)
        ERR_EXIT("bind");

    if ((listen(iListenFd, SOMAXCONN)) < 0)
        ERR_EXIT("iListenFd");

    tClientLen = sizeof(stClientAddr);
    if ((iConFd = accept(iListenFd, (struct sockaddr *)&stClientAddr, &tClientLen)) < 0)
        ERR_EXIT("accept");

    for (;;)
    {
        memset(cRecvBuf, 0, RECV_LEN);
        //printf("--- --- \n");
        iRet = read(iConFd, cRecvBuf, RECV_LEN);
        printf("%s\n", cRecvBuf);
        write(iConFd, cRecvBuf, iRet);
    }
    
    return 0;
}









