#include <stdio.h>
//6_21
void task()
{
    unsigned int ans = 0;
    unsigned int size = sizeof(ans) << 3;//4 *8=32
    unsigned int numb, c = 1;

    printf("Print number:");
    scanf("%u", &numb);

    for (int i = 0; i < size; i++)
    {
        if (!(numb & c))
        {
            numb |= c;
            break;
        }
        c <<= 1;
    }
    
    c = 1; 
    c <<= (size - 1);
    for (int i = 0; i < size; i++)
    {
        if (!(numb & c))
        {
            numb |= c;
            break;
        }
        c >>= 1;
    }

    printf("Ans=0x%X\n", numb);
    printf("Ans=%u", numb);
}

int main()
{
    task();
}