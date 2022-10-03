#include <stdio.h>
#include <math.h>
//HW5.10
double u_i(unsigned i);
double v_i(unsigned i);

double v_i(unsigned i)
{
    if ((i == 0)||(i == 1))
    {
        return 1;
    }
    return (u_i(i - 1) - v_i(i - 1)) / (abs(u_i(i - 2) - v_i(i - 1)) + 2);
}
double u_i(unsigned i)
{
    if ((i == 0)||(i == 1))
    {
        return 0;
    }
    double ui2 = u_i(i - 1);
    double vi2 = v_i(i - 1);
        
    return (ui2 - u_i(i - 2) * vi2 - v_i(i - 2))/(1 + ui2 * ui2 + vi2 * vi2);
}

int main()
{
    unsigned n;
    printf("input n:");
    scanf("%u", &n);
    printf("v(%u) = %lf", n, v_i(n));
}