#include <stdio.h>
#include <math.h>
//#define printf __mingw_printf //I use VisualStudioCode with MinGw
int main()
{
    float a = 0.0001;
    double a1 = 0.0001;
    long double a2 = 0.0001;
    printf("%.2f %.2f %.2Lf\n", a, a1, a2);

    float b= 24.33e5;
    double b1 = 24.33e5;
    long double b2 = 24.33e5;
    printf("%.2f %.2f %.2Lf\n", b, b1, b2);

    float c= M_PI;
    double c1 = M_PI;
    long double c2 = M_PI;
    printf("%.2f %.2f %.2Lf\n", c, c1, c2);

    float d= sqrt(5);
    double d1 = sqrt(5);
    long double d2 = sqrt(5);
    printf("%.2f %.2f %.2Lf\n", d, d1, d2);

    float e= log(100);
    double e1 = log(100);
    long double e2 = log(100);
    printf("%.2f %.2f %.2Lf\n", e, e1, e2);
}