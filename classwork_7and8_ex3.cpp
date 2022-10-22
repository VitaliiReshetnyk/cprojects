#include <stdio.h>
#include <stdint.h>
void task6_3()
{
    uint64_t m;
    uint8_t j;

    printf("m=");
    scanf("%llu", &m);
    
    printf("j=");
    scanf("%hhu", &j);

    m = m & ~(1<<(j-1));
    
    printf("m=%llu", m);
}

int main()
{
    task6_3();
}