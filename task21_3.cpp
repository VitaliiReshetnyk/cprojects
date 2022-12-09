#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//21_3
using namespace std;

double func_a(vector <double> a, int k)
{
    sort(a.begin(), a.end());
    double sum = 0;
    if (k > a.size())
    {
        return sum;
    }
    else
    {
        for (int c = 0; c < k; c++)
        {
            sum += a[a.size() - 1 - c];
        }
    }
    return sum;
}

vector <double> func_b(vector <double> a, int k)
{
    vector <double> b;
    sort(a.begin(), a.end());
    if (k > a.size())
    {
        return b;
    }
    else
    {
        for (int c = 0; c < k; c++)
        {
            b.push_back(a[c]);        
        }
    }    
    return b;
}


int main()
{
    int n;
    vector <double> temp;
    double ttemp;
    cout << "Number of elements in vector:";
    cin >> n;
    for (int i = 0; i < n ; i++)
    {
        cout << "a["<< i+1 << "]=";
        cin >> ttemp;
        temp.push_back(ttemp);
    }
    cout << "Vector:"<<endl;
    for (double k: temp)
    {
        cout << k;
    }
    cout<< endl;

    int k;
        cout << "Number of elements in for function:";
    cin >> k;

    double a = func_a(temp, k);
    vector <double> b = func_b(temp, k);;

    cout<< "Result of func a:" << a << endl;
    cout<< "Result of func b:" << endl;
    for (double f: b)
    {
        cout << f << " ";
    }

}