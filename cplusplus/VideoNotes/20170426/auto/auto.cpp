/*
    (1)自动变量，自动获取类型，输出，泛型。
    (2)自动变量，可以实现自动循环一维数组。
    (3)自动循环的时候，对应的必须是常量。
*/

#include <iostream>

int main()
{
    auto num = 10.9; /* 自动变量，自动匹配类型 */
    auto numA = 10;

    std::cout << num << " " << numA << std::endl;

    int num1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto data : num1) /* 新型的循环：泛型 循环一维数组 */
    {
        std::cout << data << std::endl;
    }

    system("pause");
    return 0;
}

