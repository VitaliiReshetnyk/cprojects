#include <stdio.h>
//6_23
void task()
{
    unsigned ans = 0;
    unsigned size = sizeof(ans);//4 *8=32
    unsigned numb;
    printf("Print number:");
    scanf("%u", &numb);
    for (int i = 0; i < size * 8; i++)
    {
        if (!(numb & 1))
        {
            ans++;
        }
        numb >>= 1;
    }
    printf("Ans=%i", ans);
}

int main()
{
    task();
}