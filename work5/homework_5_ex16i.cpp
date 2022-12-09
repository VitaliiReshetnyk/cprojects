#include <stdio.h>
#include <math.h>
//hw5.16i
double func(double x, double eps)
{
    double sum = 0;
    int counter = 0;
    double t = 1;
    double xs = 1;
    while (abs(t) >= eps)
    {
        sum += t;
        counter++;
        xs *= x;
        if (counter % 2)
        {
            t = - (counter + 1) * (counter + 2) * xs / 2;
        }
        else
        {
            t = (counter + 1) * (counter + 2) * xs / 2;
        }
    }
    return sum;
}

int main()
{
    double x, eps;
    printf("x=:");
    scanf("%lf", &x);
    printf("Eps=:");
    scanf("%lf", &eps);
    printf("Ans = %lf", func(x, eps));    
}