#include <stdio.h>
#include <stdlib.h>
#define M 100
#define N 100
//8_7
double determinantOfMatrix(double mat[N][N], int n);
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




int main()
{
    double matrix[M][M];
    int m;
    printf("m:");
    scanf("%u", &m);
    inputmatrix(matrix, m);
    showmatrix(matrix, m);
    double ans = determinantOfMatrix(matrix, m);
    printf("ans = %lf", ans);
}


void getCofactor(double mtrx[N][N], double temp[N][N], int p,
                 int q, int n)
{
    int i = 0, j = 0;
 
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mtrx[row][col];
 
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 

double determinantOfMatrix(double mtrx[N][N], int n)
{
    double Ans = 0;

    if (n == 1)
        return mtrx[0][0];
 
    double temp[N][N];
 
    int sign = 1;

    for (int f = 0; f < n; f++)
    {
        getCofactor(mtrx, temp, 0, f, n);
        Ans += sign * mtrx[0][f] * determinantOfMatrix(temp, n - 1);
        sign = -sign;
    }
    return Ans;
}