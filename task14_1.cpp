#include <iostream>
#include <fstream>
#include <vector>
//14_1

using namespace std;

void func_1(string name)
{
    fstream f;
    f.open(name);
    string a;
    getline(f, a);
    f.close();
    
    int sum = 0;
    int temp = 0;
    int ttmp = 0;
    string sub = "";
    for (char b: a)
    {
        //cout<<b<<endl;
        if ((b != '+')&&(b != '-')&&(b != '='))
        {
            sub+=b;
        }
        else
        {
            if (ttmp == 0)
            {
                //cout<<sub<<endl;
                sum += stoi(sub);
                ttmp = 1;
                if (b=='-') {temp = -1;}
                if (b=='+') {temp = 1;}
                sub = "";
            }
            else
            {
                if (temp == -1)
                {
                    sum -= stoi(sub);
                }
                if (temp == 1)
                {
                    sum += stoi(sub);
                }
                //cout<<sub<<endl;
                sub = "";
                if (b=='-') {temp = -1;}
                if (b=='+') {temp = 1;}
                if (b=='=') {temp = 0; break;}
            }
        }
        if (b == '=')
        {
            break;
        }
    }

    cout << sum << endl;

}

int main()
{
    // file like:
    //1+2+345-98=
    string a; 
    cout << "Input name of file: ";
    cin >> a; 
    //a = "14_1.txt";
    func_1(a);
}    