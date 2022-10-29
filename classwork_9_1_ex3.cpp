#include <stdio.h>
#define N 20
#define M 20
//8.3

int inptmatrix(double mtrx[M][N], unsigned m, unsigned n)
{
    if ((m > M)||(n > N))
    {
        printf("Incorect indeces");
        return 0;
    }
    double temp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("a[%i][%i]=", i, j);
            scanf("%lf", &temp);
            mtrx[i][j] = temp;
        }
    }
    return 1;
}
int showmatrix(double mtrx[M][N], unsigned m, unsigned n)
{
    if ((m > M)||(n > N))
    {
        printf("Incorect indeces");
        return 0;
    }
    double temp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", mtrx[i][j]);
        }
        printf("\n");
    }
    return 1;
}


int main()
{
    double matrix[M][N];
    unsigned m, n;
    printf("m:");
    scanf("%u", &m);
    printf("n:");
    scanf("%u", &n);
    inptmatrix(matrix, m, n);
    showmatrix(matrix, m, n);
}

