#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
//12_6


using namespace std;

int main()
{
    vector <double> c;

    string s;
    getline(cin,s);
    istringstream is(s);
    double n;
    char g = '\0';
    while(is >> n)
    {
        is >> g;
        c.push_back(n);
    }

    
    for(const auto &a: c)
    {
        if (a > __DBL_MIN__)
        {
            cout.precision(5);
            cout << "log(" << fixed << a << ") = " << log(a);
            cout << " = " << scientific << log(a) << endl;
        }
        else
        {
            cout.precision(5);
            cout << "log(" << fixed << a << ") = NONE" << endl;
        }
    }

}