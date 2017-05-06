
#include <iostream>

int main1()
{
    int num;          /* 栈中保存 */
    int *p = new int; /* 堆中保存 */

    *p = 5;

    std::cout << *p << " " << p << std::endl;

    delete p;
    system("pause");
    return 0;
}

int main()
{
    int *p = new int[10];

    for (int i = 0; i < 10; i++)
    {
        p[i] = i;
    }

    delete []p; /* 删除数组的空间 */

    system("pause");
    return 0;
}

