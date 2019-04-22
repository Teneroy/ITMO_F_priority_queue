//
// Created by alexc on 4/17/2019.
//

#include "PQueue.h"

int main()
{
    PQueue p;
    p.INSERT(3);
    p.INSERT(5);
    p.INSERT(9);
    p.INSERT(6);
    p.INSERT(8);
    p.INSERT(9);
    p.INSERT(10);
    p.INSERT(10);
    p.INSERT(18);
    p.INSERT(9);

    p.PRINT();
    std::cout << "DELETEMIN: " << p.DELETEMIN() << std::endl;
    p.PRINT();
    std::cout << "DELETEMIN: " << p.DELETEMIN() << std::endl;
    p.PRINT();
    std::cout << "DELETEMIN: " << p.DELETEMIN() << std::endl;
    p.PRINT();
    std::cout << "DELETEMIN: " << p.DELETEMIN() << std::endl;
    p.PRINT();
    std::cout << "DELETEMIN: " << p.DELETEMIN() << std::endl;
    p.PRINT();
    std::cout << "DELETEMIN: " << p.DELETEMIN() << std::endl;
    p.PRINT();
    std::cout << "DELETEMIN: " << p.DELETEMIN() << std::endl;
    p.PRINT();
    std::cout << "DELETEMIN: " << p.DELETEMIN() << std::endl;
    p.PRINT();
    std::cout << "DELETEMIN: " << p.DELETEMIN() << std::endl;
    p.PRINT();
    std::cout << "DELETEMIN: " << p.DELETEMIN() << std::endl;
    p.PRINT();

return 0;
}