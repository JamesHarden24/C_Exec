/*
   (1)函数一般不要放在命名空间内部。
   (2)命名空间的所有数据，函数，类，对象都是公有的。
   (3)命名空间中不能private，其中是透明的。
   (4)结构体内部默认公有。

   <1>using必须在命名空间后面。
   <2>如果变量重名会出现不明确错误。
*/
#include <iostream>

namespace runmove
{
    int y(5);
    int(*padd)(int, int); /* 函数指针是一个接口作用 */
}

int add(int a, int b)
{
    return a+b;
}

int main()
{
    return 0;
}
