/*
    (1)��ֵ���ǿ��Է��ڸ�ֵ����߱���ֵ��ֵ���������ڴ�����ʵ�塣
    (2)��ֵ���ڸ�ֵ���ұ�ȡ��ֵ��������������ֵ���������ڴ�Ҳ������CPU�Ĵ�����
*/
#include <iostream>

int main1()
{
    int a = 5;
    int b;

    std::cout << &a << " " << &b << std::endl;

    b = a + 1; /* bΪ��ֵ��(a+1)Ϊ��ֵ�ڼĴ����� */
    b = a + 3;

    system("pause");
    return 0;
}

void change(int &a)
{
    a = 19;
}

int main2()
{
    int a = 5;
    int & ra(a); /* ��ʼ�����ã����ñ����ʼ�� */

    ra = 3;

    std::cout << a << std::endl;

    system("pause");
    return 0;
}

int main()
{
    int num1(5);
    int num2(10);
    int *pnum(&num1);
    int* &rpnum(pnum);

    int a = 10;   /* a��ջ�� */
    int & ra = a; /* ��ֵ���� */
    int * &&pa = &a; /* && ��ֵ���� */

    system("pause");
    return 0;
}
