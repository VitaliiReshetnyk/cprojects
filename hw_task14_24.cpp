#include <iostream>
#include <fstream>
#include <vector>
//14_24

using namespace std;

void func_1(string name)
{
    fstream f;
    f.open(name, ios::in);

    string temp;
    cout << "All strings:" << endl;
    while ((!f.eof()))
    {
        getline(f, temp);
        cout << temp << endl;
    }
    f.close();

    cout << endl;
    f.open(name, ios::in);
    int ind = 0;
    cout << "Strings that have more than 60 symbols:" << endl;
    while ((!f.eof()))
    {
        getline(f, temp);
        if (temp.size() > 60)
        {
            cout << temp << endl;
            ind = 1;
        }
    }
    if (!ind)
    {
        cout<<"Nno string" << endl;
    }
    f.close();
}



int main()
{   
    func_1("test14_24.txt");
}
