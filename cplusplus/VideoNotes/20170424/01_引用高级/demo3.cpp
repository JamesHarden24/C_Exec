
#include <iostream>

using namespace std;

struct myStruct
{
    int a;
    int b;
    //�������Ĵ�С������sizeof
    void go()
    {
        cout << "Hello World" << endl;
    }
};

int main()
{
    cout << sizeof(myStruct) << endl;

    system("pause");
    return 0;
}

