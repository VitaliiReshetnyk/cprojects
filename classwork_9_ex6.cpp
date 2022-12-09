#include <stdio.h>
#include <math.h>
#define N 20
//7_6
int inpt(double *p);
void show(double *p, int k);
void vectsum(double *out, double *p1, double *p2, int m);
double scalarproduct(double *p1, double *p2, int m);
int main()
{
    double v1[N];
    int k = inpt(v1);
    show(v1, k);

    printf("\n");

    double v2[N];
    int m = inpt(v2);
    show(v1, m);
    
    printf("\n");

    if (m==k)
    {
        double v3[N];
        vectsum(v3, v1, v2, m);
        printf("Sum:\n");
        show(v3, m);

        printf("\n");

        double sm = scalarproduct(v1, v2, m);
        printf("Scalar product = %lf", sm);
    }
    else
    {
        printf("Different legth!");
    }
}


int inpt(double *p)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        printf("a[%i]=", i);
        scanf("%lf", (p + i));
        k = i;
        if (fabs(*(p + i)) < 0.000001)
        {
            break;
        }
    }
    return k;
}


void show(double *p, int k)
{
    for (int i = 0; i < N; i++)
    {
        printf("a[%i]=%lf\n", i, *(p + i));
        if (i >= k)
        {
            break;
        }
    }
}

void vectsum(double *out, double *p1, double *p2, int m)
{
    for (int i = 0; i <= m; i++)
    {
        *(out + i) = *(p1 + i) + *(p2 + i);
    }
}

double scalarproduct(double *p1, double *p2, int m)
{
    double ans = 0;
    for(int i = 0; i <= m; i++)
    {
        ans += (*(p1 + i)) * (*(p2 + i));
    }
    return ans;
}
