#include <stdio.h>
#include <math.h>

int main()
{
    //part A
    long a, b, c;
    printf("Input three numbers:\n");
    scanf("%lu %lu %lu", &a, &b, &c);
    if ((abs(a) >= 1024) || (abs(b) >= 1024) || (abs(c) >= 1024))
    {
        printf("Too big numbers!\n");
    }
    else
    {
        printf("Ans=%lu\n", a * b * c);
    }

    //part B
    long long a1, b1, c1;
    printf("Input three numbers:\n");
    scanf("%llu %llu %llu", &a1, &b1, &c1);
    if ((abs(a) >= 2097152) || (abs(b) >= 2097152) || (abs(c) >= 2097152))
    {
        printf("Too big numbers!\n");
    }
    else
    {
        printf("Ans=%llu", a * b * c);
    }
}