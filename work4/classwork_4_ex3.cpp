#include <stdio.h>
void y1() 
{
	int n;
	float x, y = 1, power = 1;

	printf("x = ");
	scanf_s("%f", &x);

	printf("n = ");
	scanf_s("%i", &n);

	for (int i = 0; i < n; i++) {
		power *= x;
		y += power;
	}

	printf("Ans = %f\n", y);
}

void y2() 
{
	int n;
	float x, y;
	
	printf("x = ");
	scanf_s("%f", &x);

	printf("n = ");
	scanf_s("%i", &n);

	printf("y = ");
	scanf_s("%f", &y);

	double sum = 1;
	float x1 = x*x;
	float y1 = y;
	for (int i = 0; i < n; i++) {
		sum += x1 * y1;
		x1 *= x1;
		y1 *= y;
	}
	printf("Ans = %f\n", sum);
}

int main()
{
	printf("Part A:\n");
	y1();
	printf("Part B:\n");
	y2();
}
