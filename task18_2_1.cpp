// 18.2 with built in functions
#include <iostream>
#include <stack>
using namespace std;

int getIntegers(std::stack<int> & st)
{
    int x;
    int k = 0;
    do
    {
        std::cout << "x = ";
        std::cin >> x;
        if(x == 0) break;
        k++;
        st.push(x);
    } while(x != 0);
    return k;
}

void printStack(const std::stack<int> s)
{
    std::stack<int> s1(s);
    while(!s1.empty())
    {
        std::cout << " " << s1.top() << ", ";
        s1.pop();
    }
}

int main()
{
    std::stack<int> stack1;
    int n = getIntegers(stack1);
    std::cout << "N = " << n << "\n";
    printStack(stack1);


}