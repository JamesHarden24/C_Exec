
#include <iostream>

enum color:char
{
    red = 'A',
    yellow,
    blue,
    green
};


int main()
{
    color mycolor = red;
    //mycolor = 1; //ȷ����ö�ٵķ�Χ�ڲ�����
    mycolor = color::blue;

    color mycolor1(red);
    color mycolor2(color::green);

    printf("%d, %c\n", red, red);
    printf("%d, %c\n", yellow, yellow);

    system("pause");
    return 0;
}




