/* 10.1, Комп. мат. 1, Решетник.
   Визначення парності числа та кратності його 8
   методом перевірки його молодших біт
*/
#include <iostream>
#include <bitset>
#include <vector>

union U
{
    unsigned int a;
    unsigned int b0:1; // Молодший біт відповідає за парність числа
    unsigned int b8:3; // Кратність 8, якщо ці три молодших біта дорівнюють 0
    //std::vector<bool> b;
    //std::bitset<16> c;
};

int main()
{
    U t;
    for (;;)
    {
        std::cout << "Please input number: ";
        std::cin >> t.a;
        
        std::cout << t.a;
        if (!t.b0)
            std::cout << " is even number\n";
        else
            std::cout << " is not even number\n";
        
        std::cout << t.a;
        if (t.b8 == 0)
            std::cout << " is multiple 8 number\n";
        else
            std::cout << " is not multiple 8 number\n";
    }
}
