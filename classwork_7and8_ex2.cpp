#include <stdio.h>
void task6_2()
{
    int n;
    unsigned m;
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%u", &m);
    int res = n | (1 << m);
    printf("r = %d", res);
}

int main()
{
    task6_2();
}