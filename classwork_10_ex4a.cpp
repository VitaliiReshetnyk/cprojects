#include <stdio.h>
#include <stdlib.h>
//9_4

double** matrix(int n)
{
    double **ptr;
    
    ptr = (double**)malloc(n * sizeof(double*)); // Виділення пам'яті під масив покажчиків на покажчики Дабл

    for (int i = 0; i < n; i++)
    {
        ptr[i] = (double*)malloc(n * sizeof(double)); // Виділення пам'яті під масив Даблов
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        ptr[i][j] = 0;
    }
    
    return ptr;
}

void free_matrix(double **ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(ptr[i]);
    }
    free(ptr);
}

void inputmatrix(double** a, int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("Line N%i\n", j);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &a[j][i]);
        }
    }    
}

void showmatrix(double** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
}


double** multiplication(double** ptr1, double** ptr2, int n)
{
    double **ptr3 = matrix(n);
    double temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp = 0;
            for (int k = 0; k < n; k++)
            {
                temp += ptr1[i][k]*ptr2[k][j];
            }
            ptr3[i][j] = temp;
        }
    }

    return ptr3;
}




int main()
{   
    int n;
    printf("Print n:");
    scanf("%i", &n);

    double **ptr1 = matrix(n);
    double **ptr2 = matrix(n);

    printf("matrix1:\n");
    inputmatrix(ptr1, n);
    printf("\n");
    showmatrix(ptr1, n);
    printf("\n");
    printf("matrix2:\n");
    inputmatrix(ptr2, n);
    printf("\n");
    showmatrix(ptr2, n);
    printf("\n");

    double **ptr3 = multiplication(ptr1, ptr2, n);
    printf("matrix1*matrix2=\n");
    showmatrix(ptr3, n);

    free_matrix(ptr1, n);
    free_matrix(ptr2, n);
    free_matrix(ptr3, n);
}