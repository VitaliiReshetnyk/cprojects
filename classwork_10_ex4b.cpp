#include <stdio.h>
#include <stdlib.h>
//9_4b

double* matrix(int n)
{
    double *ptr;
    
    ptr = (double*)malloc(n * n * sizeof(double*));

    for (int i = 0; i < n * n; i++)
    {
        ptr[i] = 0;
    }
    
    return ptr;
}

void free_matrix(double *ptr)
{
    free(ptr);
}

void inputmatrix(double* a, int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("Line N%i\n", j);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &a[j * n + i]);
        }
    }    
}

void showmatrix(double* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", a[i * n + j]);
        }
        printf("\n");
    }
}


double* multiplication(double* ptr1, double* ptr2, int n)
{
    double *ptr3 = matrix(n);
    double temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp = 0;
            for (int k = 0; k < n; k++)
            {
                temp += ptr1[i * n + k]*ptr2[k * n + j];
            }
            ptr3[i * n + j] = temp;
        }
    }

    return ptr3;
}




int main()
{   
    int n;
    printf("Print n:");
    scanf("%i", &n);

    double *ptr1 = matrix(n);
    double *ptr2 = matrix(n);

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

    double *ptr3 = multiplication(ptr1, ptr2, n);
    printf("matrix1*matrix2=\n");
    showmatrix(ptr3, n);

    free_matrix(ptr1);
    free_matrix(ptr2);
    free_matrix(ptr3);
}