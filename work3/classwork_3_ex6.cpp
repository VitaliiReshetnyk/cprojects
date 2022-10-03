#include <stdio.h>
#include <math.h>
#define min(a, b) ((abs(a)) < (abs(b)) ? (a) : (b))
#define max(a, b) ((abs(a)) > (abs(b)) ? (a) : (b))
int main()
{
	float a, b, c;
	printf("Input three values:\n");
	scanf("%f %f %f", &a, &b, &c);
	printf("Min is=%f\n", min(min(a, b), c));
	printf("Max is=%f\n", max(max(a, b), c));
}