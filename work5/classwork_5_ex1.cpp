#include <stdio.h>
void task1()
{
    double a, b = 0;
    int k = 1;
    printf("Input a =:");
    scanf("%lf", &a);
    while (true)
    {
        if ((a - b) < 0)
        {
            printf("Part A:\n");
            printf("Ans = %lf\n", b);
            printf("Part B:\n");
            printf("n = %i\n", k);
            break;
        }
        else
        {
            b += 1. / k;
            k++;
        }
    }
}

int main()
{
    task1();
}
