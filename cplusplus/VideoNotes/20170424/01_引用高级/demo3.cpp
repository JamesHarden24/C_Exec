
#include <iostream>

using namespace std;

struct myStruct
{
    int a;
    int b;
    //代码区的大小不计入sizeof
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

