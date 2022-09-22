#include <stdio.h>
//4a
float polynom (float x)
{
    return (x*x+1)*(x*x+1);
}
int main()
{
    float x;
    printf("Input x:\n");
    scanf("%f", &x);
    printf("Ans=%f", polynom(x));
}