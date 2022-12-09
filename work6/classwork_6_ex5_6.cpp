#include <stdio.h>
//5_6
double bn(double b, unsigned n)
{
    if (b <= __DBL_MIN__)
    {
        return 0;
    }
    double res = b;
    for (unsigned i = 1; i <= n; i++)
    {
        res = b + 1/res;
    }
    return res;
}
double lambda(unsigned n, unsigned k)
{   
    if (k == 0)
    {
        return 4 * n + 2;
    }
    else
    {
        return 4*(n - k) + 2 + 1/lambda(n, k - 1);
    }
}

double x2n(unsigned n)
{   
    double res = 2;
    for (unsigned i = 0; i < 2*n-1; i++)
    {
        res = (1 + (i % 2)) + 1/res;
    }
    return res;   
}


int main()
{
    double b;
    unsigned n;
    
    printf("part A:\n");
    printf("input b:");
    scanf("%lf", &b);
    printf("input n:");
    scanf("%u", &n);
    printf("Ans=%lf\n", bn(b, n));

    printf("part B:\n");
    printf("input n:");
    scanf("%u", &n);    
    printf("Ans=%lf\n", lambda(n, n));

    printf("part C:\n");
    printf("input n:");
    scanf("%u", &n);    
    printf("Ans=%lf\n", x2n(n));
}