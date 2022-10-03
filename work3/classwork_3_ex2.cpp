#include <stdio.h>
int main()
{
    int a;
    printf("Print number:");
    scanf("%i", &a);
    int b = a;
    int units = b % 10;
    b/=10;
    int tens = b % 10;
    b/=10;
    int hundreds = b;
    if ((a < 100) || (a > 999) || (units == tens) || (tens == hundreds) || (units == hundreds))
    {
        printf("Incorect number!!!");
    }
    else
    {
        printf("%i%i%i\n", units, tens, hundreds);
        printf("%i%i%i\n", units, hundreds, tens);
        printf("%i%i%i\n", hundreds, units, tens);
        printf("%i%i%i\n", hundreds, tens, units);
        printf("%i%i%i\n", tens, hundreds, units);
        printf("%i%i%i\n", tens, units, hundreds);
    }
}
