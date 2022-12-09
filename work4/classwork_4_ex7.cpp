#include <stdio.h>
void task7() 
{
	unsigned i, n;
	float x, y, a;

	printf("x = ");
	scanf_s("%f", &x);

	printf("n = ");
	scanf_s("%u", &n);

	y = 1;
	a = 1;

	for (unsigned i = 1; i <= n; i++)
    {
		a *= (x / i);
		y += a;
	}

	printf("y = %lf", y);

}
int main()
{
    task7();
}