/*
    (1)�Զ��������Զ���ȡ���ͣ���������͡�
    (2)�Զ�����������ʵ���Զ�ѭ��һά���顣
    (3)�Զ�ѭ����ʱ�򣬶�Ӧ�ı����ǳ�����
*/

#include <iostream>

int main()
{
    auto num = 10.9; /* �Զ��������Զ�ƥ������ */
    auto numA = 10;

    std::cout << num << " " << numA << std::endl;

    int num1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto data : num1) /* ���͵�ѭ�������� ѭ��һά���� */
    {
        std::cout << data << std::endl;
    }

    system("pause");
    return 0;
}

