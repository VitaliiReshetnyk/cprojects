#include <iostream>
//10.6 є

typedef struct 
{
    double r;
    double x;
    double y;
}circle;

circle input_circle()
{
    circle a{};
    std::cout << "Input x coordinate of center: ";
    std::cin >> a.x;
    std::cout << "Input y coordinate of center: ";
    std::cin >> a.y;
    do{
    std::cout << "Input radius of circle: ";
    std::cin >> a.r;
    }while (a.r < 0);
    return a;
}

void print_circle(const circle a)
{
    std::cout << "Center " << "(" << a.x << ", " << a.y 
              << "), r = " << a.r << std::endl; 
}


int main()
{
    circle a1 = input_circle();
    print_circle(a1);
}