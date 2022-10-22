#include <stdio.h>
#define N 5
//7_4
void inpt(int *p)
{
    for (int i = 0; i < N; i++)
    {
        printf("a[%i]=", i);
        scanf("%i", (p + i));
    }
}

void mx(int *p)
{
    int ans = *p;
    for (int i = 0; i < N; i++)
    {
        if (ans < *(p+i))
        {
            ans = *(p+i);
        }
    }
    printf("Max = %i", ans);
}

void show(int *p)
{
    for (int i = 0; i < N; i++)
    {
        printf("a[%i]=%i\n", i, *(p+i));
    }
}



int main()
{
    int a[N];
    int *b = &a[0];
    inpt(b);
    mx(b);
    printf("\n\n\n");
    show(b);
}