#include <stdio.h>
#include <math.h>
int main()
{
    float x;
    printf("Input number:");
    scanf("%f", &x);
    int xint = (int)x;
    printf("Int part:%i\n", xint);
    float xfloat = x - xint;
    printf("Fractional part:%.2f\n", xfloat);
    printf("Biggest int number smaller than this (rounding down):%i\n", xint);
    printf("Least int number bigger than this (rounding up):%i\n", xint+1);
    
    printf("With math.h:\n");
    printf("up round:%f\n", ceil(x));
    printf("down round:%f\n", floor(x));
    printf("round:%f\n", round(x));
}