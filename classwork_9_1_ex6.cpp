#include <stdio.h>
#define N 100
#define M 100
//8_6

void inputmatrix(double a[N][M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        printf("Line N%i\n", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }    
}

int showmatrix(double mtrx[N][M], int n, int m)
{
    if ((m > M)||(n > N))
    {
        printf("Incorect indeces");
        return 0;
    }
    double temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%lf ", mtrx[i][j]);
        }
        printf("\n");
    }
    return 1;
}


void func(double mtrx[N][M], int n, int m, int k)
{
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i-j)==k)
            {
                ans += mtrx[i][j];
                //printf("%lf\n", mtrx[i][j]);
            }
        }
    }
    printf("ans = %lf", ans);
}



int main()
{
    double matrix[N][M];
    int m, n, k;
    printf("m:");
    scanf("%u", &m);
    printf("n:");
    scanf("%u", &n);
    printf("k:");
    scanf("%i", &k);
    inputmatrix(matrix, n, m);
    showmatrix(matrix, n, m);
    func(matrix, n, m, k);
}