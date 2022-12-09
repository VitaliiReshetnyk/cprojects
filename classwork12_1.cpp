#include <iostream>
#include <cmath>
//12_1s
using namespace std;

int main()
{
    double x,y;
    
    cout << "Input x:";
    cin >> x;

    cout << "Input y:";
    cin >> y;

    double z = pow(x, y);

    cout << "x^y : " << scientific << z;


}