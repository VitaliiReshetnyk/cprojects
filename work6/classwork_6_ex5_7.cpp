#include <stdio.h>
//5_7
double bk(unsigned k);
double ak(unsigned k)
{
    if (k == 1)
    {
        return 0;
    }
    if (k == 2)
    {
        return 1;
    }
    return (double)ak(k - 1) / k + ak(k - 2) * bk(k);
}
double bk(unsigned k)
{
    if (k == 1)
    {
        return 1;
    }
    if (k == 2)
    {
        return 0;
    }
    return (double)bk(k - 1) + ak(k - 1);
}
int main()
{
    unsigned n;
    printf("Print n:");
    scanf("%u", &n);
    double sum = 0;
    double two = 2;
    for (int k = 1; k <= n; k++)
    {
        sum += two/(ak(k) + bk(k));
        two *= 2;
    }
    printf("Ans=%lf", sum);
}