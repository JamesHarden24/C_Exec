/*******************************************************************************
c++中的命名空间
    在C语言中只是一个全局作用域
    C语言中所有的全局标识符共享一个区域
    标识符之间可能发生冲突
C++中提出了命名空间的概念
    命名空间将全局作用域分成不同的部分
    不同命名空间中的标识符可以同名而不会发生冲突
    命名空间可以相互嵌套
    全局作用域也叫默认命名空间

C++命名空间的使用
    namespace name {...}

    使用整个命名空间: using namespace name;
    使用命名空间中的变量: using name::variable
    使用默认命名空间中的变量: ::variable
    默认情况下可以直接使用默认命名空间的所有标识符
*******************************************************************************/
#include <iostream>

using namespace std;

namespace NameSpaceA
{
    int a = 0;
}

namespace NameSpaceB
{
    int a = 1;

    namespace NameSpaceC 
    {
        struct Teacher
        {
            char name[10];
            int age;
        };
    }
}

int main()
{
    using namespace NameSpaceA;
    using NameSpaceB::NameSpaceC::Teacher;

    cout << a << endl;
    cout << NameSpaceB::a << endl;

    Teacher tl = {"aaa", 3};

    cout << tl.name << endl;
    cout << tl.age << endl;

    system("pause");
    return 0;
}


















