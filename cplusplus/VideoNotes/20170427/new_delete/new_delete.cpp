
#include <iostream>

int main1()
{
    int num;          /* ջ�б��� */
    int *p = new int; /* ���б��� */

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

    delete []p; /* ɾ������Ŀռ� */

    system("pause");
    return 0;
}

