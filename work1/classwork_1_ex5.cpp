#include <stdio.h>
int main()
{
    //a
    float x;
    printf("Input number:");
    scanf("%f", &x);
    x*=x;
    x*=x;
    printf("x^4=%.3f", x);
}