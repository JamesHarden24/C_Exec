
#include <stdio.h>
#include <arpa/inet.h>

int main(void)
{
    unsigned long ulAddr = inet_addr("192.168.1.102");
    struct in_addr stIpAddr;

    printf("---%u---\n", ntohl(ulAddr));
    stIpAddr.s_addr = ulAddr;

    printf("%s\n", inet_ntoa(stIpAddr));

    return 0;
}



