#include <stdio.h>
#include <math.h>
float Rosenbrock2d(float x, float y){
    return 100*(x*x - y)*(x*x - y) + (x - 1) * (x - 1);
}
int main()
{
    printf("f(1, 0)=%f\n", Rosenbrock2d(1, 0));
    printf("f(2, 3)=%f\n", Rosenbrock2d(2, 3));
    printf("f(4, 5)=%f\n", Rosenbrock2d(4, 5));
}