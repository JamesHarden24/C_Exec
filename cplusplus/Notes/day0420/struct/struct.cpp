/*******************************************************************************
struct类型的增强
C语言的struct定义了一组变量的集合，C编译器并不认为这是一种新的类型。
C++语言中struct是一个新类型的定义声明
*******************************************************************************/
#include <iostream>

using namespace std;

struct Student
{
    char name[100];
    int age;
};

int main()
{
    Student s1 = {"wang", 10};
    Student s2 = {"liu", 11};

    return 0;
}

