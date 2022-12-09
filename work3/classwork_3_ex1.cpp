#include <stdio.h>
int main()
{
    int a;
    printf("Print number:");
    scanf("%i", &a);
    if ((a < 100) || (a > 999))
    {
        printf("Incorect number!!!");
    }
    else
    {
        int b = a;
        int units = b % 10;
        b/=10;
        int tens = b % 10;
        b/=10;
        int hundreds = b;
        //part A of exercise
        printf("%i = %i*100 + %i*10 + %i\n", a, hundreds, tens, units);
        //part B of exercise
        printf("Sum = %i\n", hundreds + tens + units);
        //part C of exercise
        printf("Inverse(%i) = %i%i%i\n", a, units, tens, hundreds);
    }
}