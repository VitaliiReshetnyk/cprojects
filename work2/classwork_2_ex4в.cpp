#include <stdio.h>
#include <math.h>
float polynom(float x){
    float y = x + 1;
    x = y*y;
    x*=x;
    x*=y;
    return  x;
}
int main()
{
    float x;
    printf("Input x:\n");
    scanf("%f", &x);
    printf("Ans=%f", polynom(x));
}
