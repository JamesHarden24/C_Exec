/*
    1)������Ϊ�����������˻�Ϊָ��;
    2)���β�������ֵ�char buf[30],int a[10] C/C++�����������������ָ�룬Ҳ��������
      �ķ����ڴ�;
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[])
{
    int a[10] = { 1, 5, 44, 85, 89, 9, 8, 67, 45, 33};
    int i, j;
    int temp;

    for (i = 0; i < 10; i++)
    {
        for (j = i; j < 10; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        printf("====a[%d] = %d ======\n", i, a[i]);
    }

    system("pause");
    return 0;
}


