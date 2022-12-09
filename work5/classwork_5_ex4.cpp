#include <stdio.h>
double aka( int n)
{
    double ans = 1;
    for(int i = 1; i <= n; i++)
    {
        ans *= 1.0 / i;
    }
    ans += 1;
    return ans;
}

double P_A(int n)
{
    return (n == 0) ? 1 : P_A(n - 1) * aka(n);
}

double akb(long long n)
{
    long long two = 1;
    double ans;
    for (int i = 0; i <= n; i++)
    {
        two *= -2;
    }
    ans = n * n / (double)two;
    ans += 1;
    return ans;
}

double P_B(long long n)
{
    return (n == 0) ? 1 : P_B(n - 1) * akb(n);
}


int main()
{
    long long n;
    
    printf("Part A:\n");
    printf("Print N = ");
    scanf("%llu", &n);
    printf("Ans = %lf\n", P_A(n));

    printf("Part B:\n");
    printf("Print N = ");
    scanf("%llu", &n);
    printf("Ans = %lf\n", P_B(n));
}