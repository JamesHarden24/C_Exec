/*
    C++��һ��ǿ��������:
    (1)�ؼ���constԼ������ķ������ʣ�ʹ����ֵֻ�ܶ�������д�����������޸Ķ����ֵ��
    (2)C++�����޶�Ȩ�ޣ�ָ������ָ����������ϸ������͡�

    ������
        const ������ & ������ = ������
*/
#include <iostream>

int main1()
{
    const int num = 5;
    int a[num];
    int i = 0;

    for (auto data : a)
    {
        data = i++;
    }

    system("pause");
    return 0;
}

int main2()
{
    const int num = 5;
    int *p = const_cast<int*>(&num);

    *p = 4; /* ��Ȼ����ִ�У����ܸ�ֵ�� */
    std::cout << num << std::endl;

    system("pause");
    return 0;
}


int main3()
{
    int a = 0;
    const int b = 30;
    int *const pa(&a);
    const int *pb(&b);

    *pa = 50;
    pb = &a;

    system("pause");
    return 0;
}


int main()
{
    const int num = 0;
    const int & rnum = num;

    std::cout << rnum << num << std::endl;

    system("pause");
    return 0;
}
