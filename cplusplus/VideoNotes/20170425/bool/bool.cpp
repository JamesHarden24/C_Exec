
#include <iostream>

int main()
{
    bool b1 = 1 && 1 || 2 || -1 && 0;

    std::cout << typeid(b1).name() << std::endl;
    std::cout << b1 << std::endl;
    decltype(b1) bt(1+23);

    system("pause");
    return 0;
}



