#include <stdio.h>
#define N 10
#define _USE_MATH_DEFINES
#include <math.h>


//7_3
double sumE(double arr[N])
{
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > M_E)
        {
             sum += arr[i];
        }
    }
    return sum;
}


int main()
{
    double arr[N];
    for (int i = 0; i < N; i++)
    {
        printf("a[%i]=", i);
        scanf("%lf", &arr[i]);
    }
    double s1 = sumE(arr);
    printf("sum = %lf", s1);
}