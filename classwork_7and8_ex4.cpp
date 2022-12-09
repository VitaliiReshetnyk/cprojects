#include <stdio.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS 1
#include <inttypes.h>
void task6_4()
{
    uint32_t n;

    printf("n:\n");
    int r = scanf("%u", &n);
    if (r != 1)
    {
        printf("cannot input");
        return;
    }

    printf("%x\n", n);

    uint32_t first8bit = n & 0xFF;
    uint32_t last8bit = n >> 24;

    uint32_t m = ((n<<8)>>16)<<8;
    m |= (first8bit<<24);
    m |= last8bit;

    printf("m= %u, %x",m,m);
}

int main()
{
    task6_4();
}