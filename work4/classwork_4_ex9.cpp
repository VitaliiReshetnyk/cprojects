#include <stdio.h>
void task9()
{
	unsigned r = 0, n, x = 1;

	printf("m = ");
	scanf_s("%u", &n);

	while (x <= n) {
		x *= 2;
		r++;
	}

	printf("2^r = %u\n", x);
    printf("r = %u\n", r);
}

int main()
{
    task9();
}