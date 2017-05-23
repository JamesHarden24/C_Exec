/*
   数据类型分为两种，简单和复杂，思考复杂数据类型的时候，不能用简单数据类型思考之。

   数据类型的本质
   >> 数据类型可以理解为创建变量的模子: 是固定大小内存块的别名
   >> 数据类型的作用: 编译器预算对象(变量)分配的内存空间大小

   void的字面意思是"无类型"，void*则为"无类型指针"，void*可以指向任何类型的数据。
   用法1)数据类型的封装。
   用法2)void *修饰函数返回值和参数，仅表示无。

   void指针的意义  把一个不知道数据类型的指针传出

   变量的本质是(一段连续)内存空间的别名，变量是一个标号
*/

#include <stdio.h>
#include <stdlib.h>

int main01(int argc, const char *argv[])
{
    int a[10] = { 1, 5, 44, 85, 89, 9, 8, 67, 45, 33};

    printf("a:%d, &a:%d\n", a, &a); //a, &a大小一样
    printf("a+1:%d, &a+1:%d\n", a+1, &a+1); //大小不一样

    system("pause");
    return 0;
}

typedef int u32;

int main(int argc, const char *argv[])
{
    printf("----%d----\n", sizeof(u32));

    system("pause");
    return 0;
}

