/*
    1)数组作为函数参数会退化为指针;
    2)在形参里面出现的char buf[30],int a[10] C/C++编译器都会把它当成指针，也不会主动
      的分配内存;
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


