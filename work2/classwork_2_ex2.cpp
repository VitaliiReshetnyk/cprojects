#include <stdio.h>
#include <math.h>
float hipot (float a, float b)
{
    return sqrt(a*a + b*b);
}
int main()
{
    float a,b;
    printf("Input a b:\n");
    scanf("%f %f", &a, &b);
    printf("sqrt(a^2+b^2)=%f", hipot(a,b));
}
