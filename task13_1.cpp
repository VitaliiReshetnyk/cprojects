#include <iostream>
//13_1

using namespace std;

string func_1(string a)
{
    int b = a.find(':');
    int c = a.find(',');
    if (b == -1)
    {
        return a;
    }
    else 
    {
        string d = "";
        if (c == -1)
        {
            for (int g = b + 1; g < a.length(); g++)
            {
                d += a[g];
            }
            return d;
        }
        else
        {
            for (int g = b + 1; g < c; g++)
            {
                d += a[g];
            }
            return d;
        }

    }

}


void func_2(string *a)
{
    int b = a->find(':');
    int c = a->find(',');
    if (b == -1)
    {
        // return *a;
    }
    else 
    {
        string d = "";
        if (c == -1)
        {
            for (int g = b + 1; g < a->length(); g++)
            {
                d += (*a)[g];
            }
            *a = d;
            //return d;
        }
        else
        {
            for (int g = b + 1; g < c; g++)
            {
                d += (*a)[g];
            }
            *a = d;
            //return d;
        }

    }

}

int main()
{
    string a;
    cout << "Print smth:" << endl;
    cin >> a;
    string b = func_1(a);
    cout << b << endl;
    func_2(&a);
    cout << a << endl;
}