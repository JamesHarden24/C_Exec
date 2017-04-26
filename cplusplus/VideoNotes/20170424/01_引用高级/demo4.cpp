
#include <iostream>

int main()
{
    char str[10]("hello");
    const char( &rstr)[10](str);   /* 常量引用 */
    const char( &rrstr)[10](rstr); /* 引用可以为引用初始化 */

    system("pause");
    return 0;
}
