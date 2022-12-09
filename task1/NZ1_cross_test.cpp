/* 10.1, Комп. мат. 1, Решетник.
 * main файл для крос тесту.
*/
#include <iostream>
#include "NZ1_C/NZ1_test.h"
#include "NZ1_CPP/NZ1_vectorBool.hpp"
#include "NZ1_CPP/NZ1_bitset.hpp"

#define QUANTITY 2

int main()
{
    VectorBool vectorBool;
    Bitset bitset;
    int sel = 0;

    while (true)
    {
        std::cout << "\nPlease select\n"
                << "1. Bit field test\n"
                << "2. vector<bool> test\n"
                << "3. bitset test\n"
                << "0. Exit\n" << std::endl;

        std::cin >> sel;

        switch (sel)
        {
        case 0:
            return 0;
        case 1:
            bitFieldTest();
            break;
        case 2:
            vectorBool.test();
            break;
        case 3:
            bitset.test();
            break;
        default:
            std::cout << "Wrong choise" << std::endl;
            break;
        }
    }
}
