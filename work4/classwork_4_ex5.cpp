#include <stdio.h>
void task5(int n)
{
	int sum = 1;
    for (int i = n; i > 0; i-=2)
    {
        sum *= i;
    }
	printf("Ans = %d", sum);
}

int main()
{
    int n;
    printf("n=");
    scanf("%i", &n);
    task5(n);
}