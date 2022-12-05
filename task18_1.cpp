#include <iostream>
using namespace std;

template <typename T>
T max2(T x, T y)
{
    return x>y?x:y;
}

int main()
{
    int x = 1, y = 2;
    int z = max2(x, y);

    cout << z << "\n";

    double x1 = 0.123, y1 = -2.45;
    y1 = max2(x1, y1);
    cout << y1 << "\n";

    string x2("aaa"), y2("bbb");
    cout << max2(x2, y2) << "\n";
}