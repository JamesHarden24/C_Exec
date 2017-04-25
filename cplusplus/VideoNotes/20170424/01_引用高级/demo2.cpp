/*******************************************************************************

*******************************************************************************/

#include <iostream>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

void change(int (* &rp)(int a, int b))
{
    rp = add;
}

int (*& changep(int (*&rp)(int, int)))(int, int)
{
    rp = sub;
    return rp;
}

int main()
{
    int(* p)(int a, int b)(add);
    cout << p(3, 4) << endl;

    int(* &rp)(int a, int b)(p); /* 引用函数指针 */
    rp = sub;

    cout << p(3, 4) << endl;

    change(p);
    cout << p(3, 4) << endl;

    p = changep(p);
    cout << p(3, 4) << endl;

    system("pause");
    return 0;
}










