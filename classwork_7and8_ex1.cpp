#include <stdio.h>
void task6_1()
{
    unsigned char n;
    printf("n=");
    scanf("%hhu", &n);
    long long unsigned m = 1UL << n;
    printf("m = %Lu", m);
}

int main()
{
    task6_1();
}