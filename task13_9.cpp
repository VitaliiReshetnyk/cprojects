#include <iostream>
#include <vector>
//13_9

using namespace std;

vector <string> func_1(string a)
{
    vector <int> c;
    for (int d = 0; d < a.length(); d++)
    {
        //cout << a[d] << endl;
        if ((a[d] == ' ')||(a[d] == ','))
        {
            c.push_back(d);
        }
    }

    vector <string> b;

    if (c[0] != 0)
    {
        string ttemp = "";
        for (int j = 0; j < c[0]; j++)
        {
            ttemp += a[j];
        }
        b.push_back(ttemp);
    }

    for (int i = 1; i < c.size(); i++)
    {
        if ((c[i] - c[i-1]) > 1)
        {
            string ttemp = "";
            for (int j = c[i - 1]+1; j < c[i]; j++)
            {
                ttemp += a[j];
            }
            b.push_back(ttemp);
        }
    }

    if (c[c.size()-1] != (a.length()-1))
    {
        string ttemp = "";
        for (int j = c[c.size()-1] + 1; j < a.length(); j++)
        {
            ttemp += a[j];
        }
        b.push_back(ttemp);
    }    
    return b;
}

void func_2(string a, char b)
{
    vector <string> c = func_1(a);
    for (string j: c)
    {
        if (j[j.size()-1]==b)
        {
            cout << j << endl;
        }
    }
}

int main()
{
    string a; 
    int n;
    cout << "Print smth:" << endl;
    getline(cin, a);
    cout << "Print symbol" << endl;
    char b;
    cin >> b;
    func_2(a, b);
}    