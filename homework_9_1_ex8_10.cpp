#include <stdio.h>
#include <stdlib.h>
#define M 100
#define N 100
//8_10
void inputmatrix(double a[M][M], int m)
{
    int n = m;
    for (int j = 0; j < n; j++)
    {
        printf("Line N%i\n", j);
        for (int i = 0; i < m; i++)
        {
            scanf("%lf", &a[j][i]);
        }
    }    
}

int showmatrix(double mtrx[M][M], int m)
{
    int n = m;
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

void func(double mtrx[M][M], int m)
{
    double temp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m/2; j++)
        {
            temp = mtrx[i][j];
            mtrx[i][j] = mtrx[m-i-1][m-j-1];
            mtrx[m-i-1][m-j-1] = temp;
        }   
    }
}



int main()
{
    double matrix[M][M];
    int m;
    printf("n:");
    scanf("%u", &m);
    inputmatrix(matrix, 2*m);
    showmatrix(matrix, 2*m);
    func(matrix, 2*m);
    printf("\n");
    showmatrix(matrix, 2*m);

}