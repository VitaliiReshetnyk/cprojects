#include <iostream>
#include <fstream>
#include <vector>
//14_5

using namespace std;

void func_1(string name, char edge)
{
    fstream f;
    f.open(name, ios::in);

    vector <string> a;
    string temp;

    unsigned int start = 0;
    unsigned int end = 0;
    unsigned int similar = 0;
    unsigned int all = 0;

    while ((!f.eof()))
    {
        getline(f, temp);
        if (temp[0] == edge)
        {
            start++;
        }
        if (temp[temp.size()-1] == edge)
        {
            end++;
        }
        if (temp[temp.size()-1] == temp[0])
        {
            similar++;
        }
        int htem = 1;
        char f = temp[0];
        for (char g: temp)
        {
            if (g!=f)
            {
                htem = 0;
                break;
            }
        }
        if (htem)
        {
            all++;
        }
    }
    f.close();
    cout << start<< " strings in file started by this symbol:" << edge << endl;
    cout << end<< " strings in file ended by this symbol:" << edge << endl;
    cout << similar<< " have similar end and start" << endl;
    cout << all<< " consist of one type of char" << endl;
}



int main()
{   
    string h;
    cout << "Input character: ";
    cin >> h;
    func_1("test14_5.txt", h[0]);
}
