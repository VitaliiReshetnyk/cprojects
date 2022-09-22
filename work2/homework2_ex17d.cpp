#include <stdio.h>
#include <math.h>
//HW2.17
float gauss(float x)
{
    return pow(M_E, -(x*x));
}
float gauss_derivative(float x)
{
    return pow(M_E, -(x*x))*(-2*x);
}

int main()
{
    float x;
    printf("x:");
    scanf("%f", &x);
    printf("Gauss=%f\n", gauss(x));
    printf("Gauss_derivative=%f", gauss_derivative(x));
}