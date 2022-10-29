#include <stdio.h>
#define N 3
#define M 3
//8.2

void printMatrix(double a[][N], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
}

int replace(double a[N][M], unsigned n, unsigned m, double k)
{
    if ((n >= N)||(m >= M))
    {
        printf("wrond indeces\n");
        return 0;
    }
    a[n][m] = k;
    return 1;
}

void task2()
{
    double m2[N][M] = {{1.0, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};
    
    unsigned n, m; double a;

    printf("i, j:");
    scanf("%u %u", &n, &m);
    printf("a:");
    scanf("%lf", &a);

    replace(m2, n, m, a);
    printMatrix(m2, M);
}

int main()
{
    task2();
}

