#include <stdio.h>
#include <math.h>
float heron (float a, float b, float c)
{
    float p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main()
{
    float a, b, c;
    printf("Input a b c:\n");
    scanf("%f %f %f", &a, &b, &c);
    printf("S=%f", heron(a, b, c));
}