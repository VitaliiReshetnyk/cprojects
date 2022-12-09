#include <stdio.h>

long long fibon(long n)
{
    unsigned long long F0 = 0L;
    unsigned long long F1 = 1UL;
    unsigned long long F = 1UL;

    if (n == 0) return 0;
    if (n == 1) return 1
    ;
    for (int i = 1; i < n; i++)
    {
        F = F0 + F1;
        F0 = F1;
        F1 = F;
    }
    return F;
}

int main()
{
    int n;
    printf("N = ");
    scanf("%i", &n);
    printf("Fib(n) = %i\n", fibon(n));


    int i = 0;
    long long a;
    printf("A = ");
    scanf("%llu", &a);
    
    while (fibon(i) <= a)
    {
        i++;
    }
    printf("fib <= a; fib(%i) = %llu\n", i - 1, fibon(i - 1));
    if (fibon(i) == a) i++;
    printf("fib >  a; fib(%i) = %llu\n", i, fibon(i));

    long sum = 0;
    int counter = 0;
    long long temp = fibon(counter);
    while (temp <= 1000)
    {
        sum += temp;
        counter++;
        temp = fibon(counter);
    }
    printf("Sum = %llu", sum);
}