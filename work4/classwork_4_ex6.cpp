#include <stdio.h>
#include <math.h>
void task6a(int n)
{
    double ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = sqrt(ans + 2);
    }
    printf("Ans = %lf\n", ans);
}

void task6b(int n)
{
    double ans = 0;
    for(int i = n; i >= 1; i--)
    {
        ans = sqrt(ans + 3*i);
    }
    printf("Ans = %lf\n", ans);
}


int main()
{
    int n;
    printf("n = ");
    scanf("%i", &n);
    printf("Part A\n");
    task6a(n);
    printf("Part B\n");
    task6b(n);
}
