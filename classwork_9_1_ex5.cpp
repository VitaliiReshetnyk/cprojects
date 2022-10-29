#include <stdio.h>
#define M 25
//8_5

void inputmatrix(double a[M][M], int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("Line N%i\n", j);
        for (int i = 0; i < m; i++)
        {
            scanf("%lf", &a[j][i]);
        }
    }    
}

int showmatrix(double mtrx[M][M], int m, int n)
{
    if ((m > M)||(n > M))
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

void transpose(double a[M][M], int m)
{
    double temp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            temp  = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}


int main()
{
    double matrix[M][M];
    int m;
    printf("m:");
    scanf("%u", &m);
    inputmatrix(matrix, m, m);
    showmatrix(matrix, m, m);
    transpose(matrix, m);
    printf("\n");
    showmatrix(matrix, m, m);
}