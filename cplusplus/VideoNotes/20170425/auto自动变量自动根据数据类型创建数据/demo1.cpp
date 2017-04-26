#include <iostream>

int main()
{
    double db = 10.9;
    double *pdb = &db;
    auto num = pdb;

    std::cout << typeid(db).name() << std::endl;
    std::cout << typeid(num).name() << std::endl;
    std::cout << typeid(pdb).name() << std::endl;

    decltype(db) numA(10.9);

    std::cout << sizeof(numA) << "  " << numA << std::endl;

    system("pause");
    return 0;
}

