#include <stdio.h>
#include <math.h>
//4.27eHW
long mypow(int x, int y)
{
    long ans = 1;
    for (int i = 0; i < y; i++)
    {
        ans *= x; 
    }
    return ans;
}
double my_func(int k)
{
    return 1.0 / (mypow(-1, k) * (mypow(3, k)) * (2 * k + 1));
}

void task27_e()
{
    double eps, ans = 0, x0;
    printf("eps = ");
    scanf("%lf", &eps);
    x0 = my_func(0);
    int k = 1;
    while (abs(x0) >= eps)
    {
        ans += x0;
        x0 = my_func(k);
        k++;
    }
    ans *= (2 * sqrt(3));
    printf("Ans = %lf", ans);
} 

int main()
{
    task27_e();
}
