#include <stdio.h>
#include <stdlib.h>
//9_1

int main()
{
    int n;
    printf("Input number:");;
    scanf("%i", &n);
    double *ptr;

    if (!(ptr = (double*)malloc(n * sizeof(ptr))))
    {
        printf("Error: can`t allocate memmory\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("a%i=", i);
        scanf("%lf", (ptr + i));
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (*(ptr + i))*(*(ptr + i));
    }
    printf("sum of squares = %lf", sum);
    free(ptr);
}