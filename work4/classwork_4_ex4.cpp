#include <stdio.h>

int main()
{
	int n;
    double x;
    double ans = 0;
    printf("n=");
    scanf("%i", &n);
    printf("x=");
    scanf("%lf", &x);
    double x1 = x;
    for (int i = 1; i <= n; i++)
    {
        ans+=i*x1;
        x1*=x;
    }
    printf("Ans=%lf", ans);
}
