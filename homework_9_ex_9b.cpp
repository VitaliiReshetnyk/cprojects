#include <stdio.h>
#include <stdlib.h>
//7_9b

int main()
{
    int n;
    printf("Input number:");;
    scanf("%i", &n);
    unsigned int *ptr;

    if (!(ptr = (unsigned int*)malloc(n * sizeof(ptr))))
    {
        printf("Error: can`t allocate memmory\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("a%i=", i);
        scanf("%u", (ptr + i));
    }

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        //printf("%i\n", *(ptr + i));
        if (ptr[index] > ptr[i])
        {
            index = i;
        }
    }
    printf("min element: a[%i]=%u", index, ptr[index]);

    free(ptr);
}

