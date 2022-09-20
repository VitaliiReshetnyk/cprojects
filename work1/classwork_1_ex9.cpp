#include <stdio.h>
int main()
{
    float x, y;
    printf("Input number x and y:\n");
    scanf("%f %f", &x, &y);
    printf("(x+y)/2=%f=%e\n", (x + y)/2,(x + y)/2);
    printf("2/(1/x + 1/y)=%f=%e\n", 2 / ( 1 / x + 1 / y),2 / ( 1 / x + 1 / y));
}