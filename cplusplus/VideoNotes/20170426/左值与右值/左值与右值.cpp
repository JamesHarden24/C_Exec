/*
    (1)左值就是可以放在赋值号左边被赋值的值，必须中内存中有实体。
    (2)右值当在赋值号右边取出值赋给其他变量的值，可以在内存也可以在CPU寄存器。
*/
#include <iostream>

int main1()
{
    int a = 5;
    int b;

    std::cout << &a << " " << &b << std::endl;

    b = a + 1; /* b为左值，(a+1)为右值在寄存器中 */
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
    int & ra(a); /* 初始化引用，引用必须初始化 */

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

    int a = 10;   /* a在栈上 */
    int & ra = a; /* 左值引用 */
    int * &&pa = &a; /* && 右值引用 */

    system("pause");
    return 0;
}
