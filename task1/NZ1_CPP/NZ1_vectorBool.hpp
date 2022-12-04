#pragma once

#include <vector>
#include <string>

class VectorBool
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
        std::vector<bool> b = {false, false, false};
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
