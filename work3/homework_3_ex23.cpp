#include <stdio.h>
#include <math.h>
//HW3.23 softExponential

double softExponential(double a, double x)
{
	if (abs(a) <= __DBL_MIN__)
	{
		return x;
	}
	if (a > __DBL_MIN__)
	{
		return ((exp(a * x) - 1) / a) + a;
	}
	else
	{
		if ((1 - a * (x + a))<__DBL_MIN__)
		{
			return __DBL_MAX__;
		}
		return -(log(1 - a * (x + a))/a);
	}
}

double softExponentialDerivative(double a, double x)
{
	if (abs(a) <= __DBL_MIN__)
	{
		return 1;
	}
	if (a > __DBL_MIN__)
	{
		return exp(a * x);
	}
	else
	{
		if (abs(1-a*x-a*a)<__DBL_MIN__)
		{
			return __DBL_MAX__;
		}
		return 1/(1-a*x-a*a);
	}
}


int main()
{
	double a, x;
	printf("Printf two numberss:\n");
	scanf("%lf %lf", &a, &x);
	printf("softExponential(%f, %f)=%f\n", a, x, softExponential(a, x));
	printf("softExponentialDerivative(%f, %f)=%f\n", a, x, softExponentialDerivative(a, x));
}