#include <stdio.h>
#include <math.h>
//5_19

double func(double x)
{
    return (tan(x) - x);
}

int sign(double x)
{
    if (x>0)  return 1;
    if (x<0)  return -1;
    return 0;
}

double solver(double eps, double a, double b, double (*f)(double))
{
    double c, fa=f(a),fb=f(b),fc; int number = 0;
    if( fabs(fa) < eps )
    {
        return a;
    }
    if( fabs(fb) < eps ) 
    {
        return b;
    }
    if(sign(fa) == sign(fb)) 
    {
        printf("Method does not work\n");
        return 0;
    }
    for(; fabs(b - a) >= eps; number++)
    {
        c = (a + b) / 2;
        fc = f(c);
        if (fc == 0)
        {
            return c;
        }

        if (sign(fc) == sign(fa))
        { 
            a = c; 
        } 
        else 
        { 
            b = c;
        }
    }
    return c;
}


int main()
{
    double a, b, eps;
    printf("Print a:");
    scanf("%lf", &a);
    printf("Print b:");
    scanf("%lf", &b);    
    printf("Print eps:");
    scanf("%lf", &eps);    
    printf("Ans=%lf\n", solver(eps, a, b, func));
}