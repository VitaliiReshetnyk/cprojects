#include <stdio.h>
#include <stdlib.h>
//9_7

int is_two(int a)
{
    int b = 1;
    while (b <= a)
    {
        if (a==b)
        {
            return 1;
        }
        else
        {
            b = b<<1;
        }
    }
    return 0;
}
int is_three(int b)
{
    int temp;
    if (b == 1) 
    {
        return 1;
    }
    while (b > 1)
    {
        temp = b/3;
        if ((temp * 3) != b)
        {
            return 0;
        }
        else
        {
            b /= 3;
        }
    }
    return 1;
}

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

    for (int i = 0; i < n; i++)
    {
        printf("a%i=", i);
        scanf("%i", (ptr + i));
    }

    int counter2 = 0;
    int counter3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (is_two(*(ptr + i)))
        {
            counter2++;
        }
        if (is_three(*(ptr + i)))
        {
            counter3++;
        }
    }
    printf("Two:%i\n", counter2);
    printf("Three:%i\n", counter3);
    free(ptr);
}
