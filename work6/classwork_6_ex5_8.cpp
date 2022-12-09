#include <stdio.h>
#include <math.h>
//5_8
double exp(double eps, double x)
{
    double x0 = 1;
    double ans = 0;
    double counter = 1;
    while (abs(x0) > eps)
    {
        ans += x0;
        x0 *= x/counter; 
        counter++;
    }
    return ans;
}
double func(double eps, double x)
{
    double counter = 1;
    double ans = 0;
    double x1 = x;
    while (abs(x1) > eps)
    {
        ans += x1;
        x1 *= (-1) * x * x * (2 * counter - 1) / (counter * (2 * counter + 1));
        counter ++;
    }     
    return ans;
}

int main()
{
    double eps, x;
    printf("Part A:\n");
    printf("print eps:");
    scanf("%lf", &eps);
    printf("print x:");
    scanf("%lf", &x);
    printf("Ans=%lf\n", exp(eps, x));

    printf("Part B:\n");
    printf("print eps:");
    scanf("%lf", &eps);
    printf("print x:");
    scanf("%lf", &x);
    printf("Ans=%lf", func(eps, x));
    
}