/*******************************************************************************
c++�е������ռ�
    ��C������ֻ��һ��ȫ��������
    C���������е�ȫ�ֱ�ʶ������һ������
    ��ʶ��֮����ܷ�����ͻ
C++������������ռ�ĸ���
    �����ռ佫ȫ��������ֳɲ�ͬ�Ĳ���
    ��ͬ�����ռ��еı�ʶ������ͬ�������ᷢ����ͻ
    �����ռ�����໥Ƕ��
    ȫ��������Ҳ��Ĭ�������ռ�

C++�����ռ��ʹ��
    namespace name {...}

    ʹ�����������ռ�: using namespace name;
    ʹ�������ռ��еı���: using name::variable
    ʹ��Ĭ�������ռ��еı���: ::variable
    Ĭ������¿���ֱ��ʹ��Ĭ�������ռ�����б�ʶ��
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


















