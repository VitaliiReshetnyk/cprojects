#include <stdio.h>
#include <stdlib.h>
#define N 100
#define M 100
//8_21
//How am I supposed to swap columns to make their min elements be in first row?
//I changed order in columns to make element in first row min in this column
void inputmatrix(double a[N][M], int n, int m)
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

int showmatrix(double a[N][M], int n, int m)
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
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
    return 1;
}

void func(double a[N][M], int n, int m)
{
    int temp = 0;
    double temp2;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            //printf("%lf", a[i][j]);
            if (a[temp][j] > a[i][j])
            {
                temp = i;
            }
        }
        temp2 = a[temp][j];
        a[temp][j] = a[0][j];
        a[0][j] = temp2;
    }
}


int main()
{
    double matrix[N][M];
    int n, m;
    printf("n:");
    scanf("%u", &n);
    printf("m:");
    scanf("%u", &m);
    inputmatrix(matrix, n, m);
    showmatrix(matrix, n, m);
    func(matrix, n, m);
    printf("\n");
    showmatrix(matrix, n, m);
}