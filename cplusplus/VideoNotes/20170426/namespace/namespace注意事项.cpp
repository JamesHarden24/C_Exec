/*
   (1)����һ�㲻Ҫ���������ռ��ڲ���
   (2)�����ռ���������ݣ��������࣬�����ǹ��еġ�
   (3)�����ռ��в���private��������͸���ġ�
   (4)�ṹ���ڲ�Ĭ�Ϲ��С�

   <1>using�����������ռ���档
   <2>���������������ֲ���ȷ����
*/
#include <iostream>

namespace runmove
{
    int y(5);
    int(*padd)(int, int); /* ����ָ����һ���ӿ����� */
}

int add(int a, int b)
{
    return a+b;
}

int main()
{
    return 0;
}
