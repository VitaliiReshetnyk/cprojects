#pragma once

#include <bitset>
#include <vector>
#include <string>

class Bitset
{
private:

    enum
    {
        PRESENCE = 0
    ,   STANDARD = 1
    ,   BEST     = 2
    };

    struct Product_st
    {
        std::string product_name;
        std::string country_name;
        float cost;
        std::bitset<3> b;
    };

    std::vector<Product_st> Products;
    
public:
    void in_console();
    void in_file();
    void out_console();
    void out_file();
    void viewNotEU();
    void test();
};
