
#include <stdio.h>

int main(void)
{
    unsigned int uiX = 0x12345678;
    unsigned char *pucTemp = (unsigned char *)&uiX;

    printf("0x%x, 0x%x, 0x%x, 0x%x\n", pucTemp[0], pucTemp[1], pucTemp[3], pucTemp[4]);

    return 0;
}



