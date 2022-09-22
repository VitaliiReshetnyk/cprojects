//1.20
#include <stdio.h>
int main()
{
    float a,b,c;
    scanf("A=%f, B=%e, C=%f",&a,&b,&c);
    printf("%f\n", (a + b + c) / 3);
    printf("%f", (3 / ( 1 / a + 1 / b + 1 / c)));
}
