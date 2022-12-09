#include <iostream>
//10_6g

struct adress
{
    std::string city = "";
    std::string street = "";
    unsigned int house = 0;
    unsigned int flat = 0;
};

adress input_adress()
{
    adress x = adress();
    std::cout << "City:" << std::endl;
    std::cin >> x.city;
    std::cout << "Street:" << std::endl;
    std::cin >> x.street;
    std::cout << "House:" << std::endl;
    std::cin >> x.house;
    std::cout << "Flat:" << std::endl;
    std::cin >> x.flat;    
    return x;
}

void print_adress(const adress a)
{
    std::cout << a.city << ", " << a.street 
    << ", " << a.house << ", " << a.flat << std::endl;
}



int main()
{
    adress a = input_adress();
    print_adress(a);
}
