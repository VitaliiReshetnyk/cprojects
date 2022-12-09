#include <stdio.h>
#include <stdlib.h>
//9_3

double* create_array(int n)
{
    double *ptr;
    if (!(ptr = (double*)malloc(n * sizeof(ptr))))
    {
        printf("Error: can`t allocate memmory\n");
        return NULL;
    }
    return ptr;
}

void delete_array(double* ptr)
{
    free(ptr);
}

void input_array(double* ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("a%i=", i);
        scanf("%lf", (ptr + i));
    }
}



int main()
{   
    int n, m;
    double *ptr_n, *ptr_m;
    printf("Input number of elements of first array{a}:\n");
    scanf("%i", &n);
    ptr_n = create_array(n);
    input_array(ptr_n, n);
    printf("Input number of elements of second array{b}:\n");
    scanf("%i", &m);
    ptr_m = create_array(m);
    input_array(ptr_m, m);
    if (m==n)
    {
        double *ptr_k;
        ptr_k = create_array(m);
        printf("Third array c=a-b:\n");
        for (int i = 0; i < m; i++)
        {
            *(ptr_k + i) = *(ptr_n + i) - *(ptr_m + i);
            printf("c[%i]=%lf\n", i, *(ptr_k + i));
        }
        delete_array(ptr_k);
    }
    else
    {
        printf("Different sizes!");
    }
    delete_array(ptr_m);
    delete_array(ptr_n);
}