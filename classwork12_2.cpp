#include <iostream>
#include <cstdlib>
//12_2

using namespace std;

int main()
{
    char buf[11];
    long long unsigned sums = 0UL;
    long long unsigned x;

    string s;
    cin >> s;
    buf[10] = '\0';
    int k = 0;
    int i = 0;
    while (i < s.size())
    {
        buf[k++] = s[i++];

        //cout << buf<<"\n";

        char* err[100];

        x = strtoull(buf, err, 10);
        if (k>=10)
        {
            k-=10;
            x = strtoull(buf, err, 10);
            sums += x;
        }
    }
    cout << "sum is " << sums << "\n";
    
}