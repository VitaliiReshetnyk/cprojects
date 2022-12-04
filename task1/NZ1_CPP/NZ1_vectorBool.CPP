/* 10.1, Комп. мат. 1, Решетник.
   Реалізація функцій вводу та виводу
*/
#include <fstream>
#include <iostream>

#include "NZ1_vectorBool.hpp"

void VectorBool::in_console()
{
    Product_st product;

    Products.clear();

    while (true)
    {
        char answer;
        std::cout << "Add product? (Y)es / No" << std::endl;
        std::cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            unsigned int t;
            std::cout << "Name:" << std::endl;
            std::cin >> product.product_name;
            std::cout << "Country:" << std::endl;
            std::cin >> product.country_name;
            std::cout << "Cost:" << std::endl;
            std::cin >> product.cost;
            std::cout << "Presence:" << std::endl;
            std::cin >> t;
            product.b[PRESENCE] = t;
            std::cout << "Standard:" << std::endl;
            std::cin >> t;
            product.b[STANDARD] = t;
            std::cout << "Best:" << std::endl;
            std::cin >> t;
            product.b[BEST] = t;

            Products.push_back(product);
        }
        else
        {
            break;
        }
    }
}

void VectorBool::in_file()
{
    Product_st product;
    std::string ss;
    std::ifstream File;

    Products.clear();

    File.open("shop.txt");

    if (!File)
    {
        std::cout << "Error: File not open!\n";
        return;
    }

    File >> ss >> ss >> ss; // Пропускаємо "Quantity:" "3"

    while (!File.eof())
    {
        unsigned int t;

        File >> product.product_name;
        File >> ss;

        File >> product.country_name;
        File >> ss;

        File >> product.cost;
        File >> ss;

        File >> t;
        product.b[PRESENCE] = t;
        File >> ss;

        File >> t;
        product.b[STANDARD] = t;
        File >> ss;

        File >> t;
        product.b[BEST] = t;
        File >> ss;

        Products.push_back(product);
    }
}

void VectorBool::out_console()
{
    std::cout << "Quantity: " << Products.size() << '\n' << std::endl;
    for (const auto &n: Products)
    {
        std::cout << "    Name: " << n.product_name << '\n';
        std::cout << " Country: " << n.country_name << '\n';
        std::cout << "    Cost: " << n.cost         << '\n';
        std::cout << "Presence: " << n.b[PRESENCE]  << '\n';
        std::cout << "Standard: " << n.b[STANDARD]  << '\n';
        std::cout << "    Best: " << n.b[BEST]      << '\n' << std::endl;
    }
}

void VectorBool::out_file()
{
    std::ofstream File;

    File.open("out.txt");

    if (!File)
    {
        std::cout << "Error: File not open!\n";
        return;
    }

    File << "Quantity: " << Products.size() << '\n' << std::endl;
    for (const auto &n: Products)
    {
        File << "    Name: " << n.product_name << '\n';
        File << " Country: " << n.country_name << '\n';
        File << "    Cost: " << n.cost         << '\n';
        File << "Presence: " << n.b[PRESENCE]  << '\n';
        File << "Standard: " << n.b[STANDARD]  << '\n';
        File << "    Best: " << n.b[BEST]      << std::endl;
    }
}

void VectorBool::viewNotEU()
{
    for (const auto &n: Products)
    {
        if (n.b[PRESENCE] && !n.b[STANDARD])
        {
            std::cout << "    Name: " << n.product_name << '\n';
            std::cout << " Country: " << n.country_name << '\n';
            std::cout << "    Cost: " << n.cost         << '\n';
            std::cout << "Presence: " << n.b[PRESENCE]  << '\n';
            std::cout << "Standard: " << n.b[STANDARD]  << '\n';
            std::cout << "    Best: " << n.b[BEST]      << '\n' << std::endl;
        }
    }
}

void VectorBool::test()
{
    unsigned long int time = 0;
    int sel = 0;

    for (;;)
    {
        std::cout << "\nVector<bool> test. Please select...\n"
                  << "1. Read from file\n"
                  << "2. Read from console\n"
                  << "3. Out to console\n"
                  << "4. Out to file\n"
                  << "5. View presence and not EU standard\n"
                  << "6. Read from file and write file for time test\n"
                  << "0. Back previous menu\n";

        std::cin >> sel;

        switch (sel)
        {
        case 0:
            return;
        case 1:
            in_file();
            break;
        case 2:
            in_console();
            break;
        case 3:
            out_console();
            break;
        case 4:
            out_file();
            break;
        case 5:
            viewNotEU();
            break;
        case 6:
            time = clock(); // Часова мітка
            in_file();
            out_file();
            std::cout << "RunTime = " << (float)(clock() - time) / CLOCKS_PER_SEC << " s" << std::endl; // Визначення та вивід часу виконання
            break;
        }
    }
}
