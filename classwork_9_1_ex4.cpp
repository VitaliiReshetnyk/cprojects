#include <stdio.h>
#define M 25
#define N 25
//8_4

void inputmatrix(double a[M][N], int m, int n)
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

int showmatrix(double mtrx[M][N], int m, int n)
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



int main()
{
    double matrix[M][N];
    int m, n;
    printf("m:");
    scanf("%u", &m);
    printf("n:");
    scanf("%u", &n);
    inputmatrix(matrix, m, n);
    showmatrix(matrix, m, n);

}