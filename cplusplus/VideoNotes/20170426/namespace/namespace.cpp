
#include <iostream>

namespace r
{
    int a(10);
    char *str("gogogo");

    namespace run /* �����ռ��Ƕ�� */
    {
        int a(9);
    }
}

namespace run  /* �����ռ���չ */
{
    int y(12);
}

namespace r = run;

int main()
{
    std::cout << r::run::a << std::endl;
    std::cout << r::y << std::endl;

    return 0;
}


