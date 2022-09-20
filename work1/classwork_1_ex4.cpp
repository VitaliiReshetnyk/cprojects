#include <stdio.h>
int main()
{
    float m1;
    float m2;
    float r;
    const double gamma = 6.673e-11;
    printf("Input m1:");
    scanf("%f", &m1);
    printf("Input m2:");
    scanf("%f", &m2);
    printf("Input r:");
    scanf("%f", &r);
    printf("F=%e\n", gamma*(m1*m2)/(r*r));
}