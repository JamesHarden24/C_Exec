/*******************************************************************************
  引用就是原来的变量的一个别名，是同一个地址
*******************************************************************************/
#include <iostream>

int main()
{
    int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int(&ra)[10](a);
    int i = 0;
    int iLoop;

    for (iLoop = 0; iLoop < 10; iLoop++)
    {
        ra[iLoop] = i + 5;
        std::cout << ra[iLoop] << std::endl;
    }

    std::cout << a << " " << ra << std::endl;

    system("pause");
    return 0;
}


