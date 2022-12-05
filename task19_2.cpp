#include <iostream>
#include <vector>
using namespace std;

std::vector<double> inputVect(int d)
{
    std::vector<double> v;
    double tmp;
    for (int i = 0; i < d; i++)
    {
        std::cin >> tmp;
        v.push_back(tmp);
    }
    return v;
}

double norm(const std::vector<double> &v)
{
    double s = 0;
    for(auto it : v)
    {
        s += it * it;
    }
    return s;
}

double sum_vect_norm(std::vector<std::vector<double>> &v)
{
    double s = 0;
    for(auto it : v)
    {
        s += norm(it);
    }
    return s;
}

int main()
{
    int n;
    std::cout << "n = ";
    std::cin >> n;

    std::vector<double> v;

    int d;
    std::cout << "d = ";
    std::cin >> d;
    
    std::vector<std::vector<double>> vect_vect;

    for (int i = 0; i < n; i++)
    {
        v = inputVect(d);
        vect_vect.push_back(v);
    }
    double s = sum_vect_norm(vect_vect);
    std::cout << "s = " << s;
}