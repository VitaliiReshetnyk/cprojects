#include <iostream>
#include <cmath>
#include <fstream>
//12_5

using namespace std;

void task_5()
{
    char fname[255];

    cout << "file name:";
    cin >> fname;

    fstream f;
    f.open(fname);

    if(!f)
    {
        return;
    }

    long long unsigned mas[2000];
    int i = 0;
    while (f>>mas[i])
    {
        i++;
    }

    f.close();

    for (int j = i-1; j>=0; j--)
    {
        double tmp = sqrt(mas[i]);
        cout.precision(4);
        cout<<tmp<<"\n";
    }
}

int main()
{
    task_5();
}