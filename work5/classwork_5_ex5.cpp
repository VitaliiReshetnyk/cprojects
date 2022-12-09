#include <stdio.h>
int func(int n)
{
    if ((n == 1) || (n == 2) || (n == 3))
    {
        return -99;
    }
    else
    {
        return func(n - 1) + func(n - 3) + 100;
    }
}
int main()
{
    int a, b;
    int counter = 1;
    while (true)
    {
        a = func(counter);
        b = func(counter + 1);
        if ((a < 0) && (b > 0))
        {
            printf("f(%i) = %i > 0\n", counter + 1, b);
            break;
        }
        counter++;
    }
}
