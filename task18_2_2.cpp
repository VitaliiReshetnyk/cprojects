// 18.2 with rewritten functions
#include <iostream>

namespace std2{

template < class T >
class stack
{
    T mas[100];
    int n;

    public:
    stack() {n = 0;}

    stack(int m) { n = m;}

    bool empty()
    {
        return n == 0;
    }

    void push(T x)
    {
        mas[n++] = x;
    }

    bool pop();

    T top()
    {
        return mas[n-1];
    }
};
};

template <class T>
bool std2::stack<T>::pop()
{
    if(n == 0) return false;
    n--;
    return true;
}

int getIntegers(std2::stack<int> & st)
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

void printStack(std2::stack<int> s1)
{
    while(!s1.empty())
    {
        std::cout << " " << s1.top() << ", ";
        s1.pop();
    }
}

int main()
{
    std2::stack<int> stack1;
    int n = getIntegers(stack1);
    std::cout << "N = " << n << "\n";
    printStack(stack1);


}