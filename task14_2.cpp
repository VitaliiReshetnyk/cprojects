#include <iostream>
#include <fstream>
#include <vector>
//14_2

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

    while (!f.eof())
    {
        getline(f, temp);
        a.push_back(temp);
    }

    f.close();

    vector <string> innew;
    for (string h: a)
    {
        vector <string> words = splitter(h);
        for (int j = 0; j < words.size()-1; j++)
        {
            if ((words[j] == "Die") || (words[j] == "die") || (words[j] == "Der") || (words[j] == "das") || (words[j] == "Das") || (words[j] == "das"))
            {
                string ftemp = words[j + 1];
                ftemp[0] = toupper(ftemp[0]);
                words[j + 1] = ftemp; 
            }
        }
        string jk = "";
        for (int k = 0; k < words.size(); k++)
        {
            if (k == (words.size()-1))
            {
                jk += words[k];
            }
            else
            {
                jk += words[k];
                jk += " ";
            }
        }
        innew.push_back(jk);
    }

    /*
    for (string h : innew)
    {
        cout << h << endl;
    }*/

    f.open(name, ios::out);

    for (string h : innew)
    {
        f << h << endl;
    }

    f.close();

}



int main()
{   
    func_1("test14_2.txt");
}
