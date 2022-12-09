#include <iostream>
#include <fstream>
#include <vector>
//14_4

using namespace std;

vector <string> splitter(string a)
{
    vector <int> c;
    for (int d = 0; d < a.length(); d++)
    {
        if ((a[d]==' '))
        {
            c.push_back(d);
        }
    }

    vector <string> b;

    if (c[0]!=0)
    {
        string ttemp = "";
        for (int j = 0; j < c[0]; j++)
        {
            ttemp+=a[j];
        }
        b.push_back(ttemp);
    }

    for(int i = 1; i < c.size(); i++)
    {
        if ((c[i]-c[i-1]) > 1)
        {
            string ttemp = "";
            for (int j = c[i - 1] + 1; j < c[i]; j++)
            {
                ttemp += a[j];
            }
            b.push_back(ttemp);
        }
    }

    if (c[c.size()-1]!=(a.length()-1))
    {
        string ttemp = "";
        for (int j = c[c.size()-1] + 1; j < a.length(); j++)
        {
            ttemp+=a[j];
        }
        b.push_back(ttemp);
    }
    return b;
}


void func_1(string name)
{
    fstream f;
    f.open(name, ios::in);

    vector <string> a;
    string temp;

    int teg = 0;
    int j = 1;
    while ((!f.eof()) && j)
    {
        getline(f, temp);
        vector <string> tmp = splitter(temp);
        for (string h: tmp)
        {
            if (h.find("<td>")!=-1)
            {
                teg++;
            }
            if (h.find("</td>")!=-1)
            {
                teg--;
                if (teg < 0)
                {
                    cout << "Wrong!!" << endl;
                    j = 0;
                    break;
                }
            }
        }
    }
    f.close();
    if (teg)
    {
        cout << "Wrong!!!" << endl;
    }
    else
    {
        cout << "Ok!" << endl;
    }
}



int main()
{   
    func_1("test14_4in.txt");
}
