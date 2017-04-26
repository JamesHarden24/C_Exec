
#include <iostream>

namespace r
{
    int a(10);
    char *str("gogogo");

    namespace run /* 命名空间的嵌套 */
    {
        int a(9);
    }
}

namespace run  /* 命名空间拓展 */
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


