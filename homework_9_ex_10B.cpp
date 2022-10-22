#include <stdio.h>
#include <stdlib.h>
//7_10B

int main()
{
    int n;
    printf("Input number:");;
    scanf("%i", &n);
    int *ptr;

    if (!(ptr = (int*)malloc(n * sizeof(ptr))))
    {
        printf("Error: can`t allocate memmory\n");
        return 1;
    }

    int temp = 1;
    int temp1;
    for (int i = 0; i < n; i++)
    {
        printf("a%i=", i);
        scanf("%i", &temp1);
        temp *= temp1;
        ptr[i] = temp;
        printf("%i\n", ptr[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        //printf("%i\n", *(ptr + i));
        if (ptr[index] < ptr[i])
        {
            index = i;
        }
    }
    printf("max element: a[%i]=%i", index, ptr[index]);

    free(ptr);
}

