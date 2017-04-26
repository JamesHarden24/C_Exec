/*
    C++是一个强类型语言:
    (1)关键字const约束对象的访问性质，使对象值只能读，不能写，即不允许修改对象的值。
    (2)C++用于限定权限，指向常量的指针变量不会严格检查类型。

    常引用
        const 类型名 & 引用名 = 变量；
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

    *p = 4; /* 仍然不被执行，不能赋值。 */
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
