
#include <iostream>

int main()
{
    char str[10]("hello");
    const char( &rstr)[10](str);   /* �������� */
    const char( &rrstr)[10](rstr); /* ���ÿ���Ϊ���ó�ʼ�� */

    system("pause");
    return 0;
}
