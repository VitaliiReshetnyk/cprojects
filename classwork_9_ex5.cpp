#include <stdio.h>
#define N 50
//7_5
void inpt(unsigned *p)
{
    unsigned even = 0;
    unsigned odd = 0;
    for (int i = 0; i < N; i++)
    {
        printf("a[%i]=", i);
        scanf("%u", (p + i));
        if (*(p + i) == 0)
        {
            break;
        }
        if ((*(p + i) % 2))
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    printf("Odd numbers:%u", odd);
    printf("Even numbers:%u", even);
}


int main()
{
    unsigned a[N];
    unsigned *b = &a[0];
    inpt(b);
}