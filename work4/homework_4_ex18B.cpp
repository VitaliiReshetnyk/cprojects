#include <stdio.h>
//4.18HW

void task18_B()
{
    unsigned k;
    double x, ans = 1;
    printf("k = ");
    scanf("%i", &k);
    printf("x = ");
    scanf("%lf", &x);
    for (int i = 0; i < k; i++)
    {
        ans *= (-x);
    }
    printf("Ans = %lf", ans);
} 

int main()
{
    task18_B();
}
