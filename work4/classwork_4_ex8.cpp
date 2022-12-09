#include <stdio.h>
void task8() {
	unsigned k = 0, m, x = 1;

	printf("m = ");
	scanf_s("%u", &m);

	while (x <= m) {
		x *= 4;
		k++;
	}

	printf("k = %u", k - 1);
}

int main()
{
    task8();
}