#include <stdio.h>
//5_18a
unsigned func_a(unsigned k)
{
    if (k == 1)
    {
        return 1;
    }
    int a = k;
    unsigned counter = 1;
    while (a > 1)
    {
        a -= counter;
        counter++;
    }
    if (a == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    printf("Part A\n");
    unsigned k;
    printf("k:");
    scanf("%u", &k);
    printf("%u", func_a(k));
    
}