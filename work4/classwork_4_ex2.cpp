#include <stdio.h>
long factorialup(int n)
{
	long ans = 1;
	for (int i = 2; i <= n; i++)
	{
		ans*=i;
	}
	return ans;
}

long factorialdown(int n)
{
	long ans = 1;
	for (int i = n; i >= 2; i--)
	{
		ans*=i;
	}
	return ans;
}

int main()
{
	int n;
	printf("Int n:\n");
	scanf("%i", &n);
	printf("Ans = %u\n", factorialup(n));
	printf("Ans = %u\n", factorialdown(n));
}