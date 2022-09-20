#include <stdio.h>
int main()
{
    float c;
    printf("Input Celcium degrees:");
    scanf("%f", &c);
    float F = c * 9 / 5 + 32;
    printf("F=%.2f", F);
}