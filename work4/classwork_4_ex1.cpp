#include <stdio.h>
#include <math.h>

double nsin(double x, int n)
{
	double ans = x;
	for (int i = n; i > 0; i--)
	{
		ans = sin(ans);
	}
	return ans;
}

int main()
{
	int n;
	double x;
	printf("Int n and double x:\n");
	scanf("%i %lf", &n, &x);
	printf("Ans = %f", nsin(x, n));
}