#include <stdio.h>
#include <stdint.h>
//HW3.8

int main()
{
	uint32_t a, b, c, d;
	printf("Input numbers:");
	scanf("%u %u", &a, &b);
	uint64_t g = (uint64_t)a + b;
	uint64_t k = (uint64_t)a * b;
	if (g > INT32_MAX)
	{
		printf("Sum is bigger than shoud be!!!\n");
	}
	else
	{
		d = a + b;
		printf("%u + %u = %u\n", a, b, d);
	}
	if (k > INT32_MAX)
	{
		printf("Multiplication is bigger than shoud be!!!\n");
	}
	else
	{
		d = a * b;
		printf("%u * %u = %u\n", a, b, d);
	}
}