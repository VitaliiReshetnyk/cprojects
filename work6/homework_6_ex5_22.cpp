#include <stdio.h>
#include <math.h>
//5_22
double a(int k);
double b(int k);
double t(int k);
double p(int k);
double func(int k)
{
    double temp1 = a(k);
    double temp2 = b(k);
    return (temp1 + temp2)*(temp1 + temp2)/(4*t(k));
}

double a(int k)
{
    if (k == 0)
    {
        return 1;
    }
    return ((a(k - 1) + b(k - 1)) / 2);
}

double b(int k)
{
    if (k == 0)
    {
        return 1/sqrt(2);
    }
    return sqrt(a(k - 1) * b(k - 1));
}
double p(int k)
{
    if (k == 0)
    {
        return 1;
    }
    return 2*p(k - 1);
}

double t(int k)
{
    if (k == 0)
    {
        return 0.25;
    }
    double temp1 = a(k - 1);
    double temp2 = a(k);
    return t(k - 1) - p(k - 1) * (temp1 - temp2)*(temp1 - temp2);
}

int main()
{
    int k;
    printf("Print k:");
    scanf("%i", &k);    
    printf("Ans = %lf\n", func(k));
}