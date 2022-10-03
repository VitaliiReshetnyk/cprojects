#include <stdio.h>
#include <math.h>

int sqr_eqn_solve(double a, double b, double c) {
	double D = b * b - 4 * a * c;
	double x1, x2;

	if (fabs(a) < 0.000001) {
		if (fabs(b) < 0.0000001) {
			if (fabs(c) < 0.0000001) {
				printf("INFINITY");
				return -1;
			}
			printf("Not equation");
			return 0;
		}
		x1 = -c / b;
		if (x1 < 0.){
			printf("No roots\n");
			return 0;
		}
		printf("Two linear roots");
		x1 = sqrt(x1);
		x2 = -x1;
		printf("x1 = %lf, x2 = %lf\n", x1, x2);
		return 2;
	}

	if (D < 0) {
		printf("No roots\n");
		return 0;
	}
	else if (fabs(D)<0.000000001) {
		x1 = -b / 2 / a;
		if (x1 < 0.){
			printf("No roots\n");
			return 0;
		}
		printf("Two roots");
		printf("x1 = %lf, x2 = %lf\n", sqrt(x1), -sqrt(x1));
		return 2;
	}
	else {
		x1 = (-b - sqrt(D)) / 2 / a;
		x2 = (-b + sqrt(D)) / (2 * a);		
		if ((x1 < 0.) && (x2 < 0.)){
			printf("No roots\n");
			return 0;
		}
		if ((x1 > 0.) && (x2 < 0.)){
			printf("Two roots");
			printf("x1 = %lf, x2 = %lf\n", sqrt(x1), -sqrt(x1));
			return 2;
		}
		if ((x1 < 0.) && (x2 > 0.)){
			printf("Two roots");
			printf("x1 = %lf, x2 = %lf\n", sqrt(x2), -sqrt(x2));
			return 2;
		}
		if ((x1 > 0.) && (x2 > 0.)){
			printf("Four roots");
			printf("x1 = %lf, x2 = %lf, x3 = %lf, x4 = %lf,\n", sqrt(x2), -sqrt(x2), sqrt(x1), -sqrt(x1));
			return 4;
		}
	}
	return -1;
}

int main()
{
	double a, b, c;

	printf("Include a, b, c: ");
	scanf_s("%lf %lf %lf", &a, &b, &c);
	printf("Equation %lf*x^4 + %lf*x^2 + %lf = 0, has %d roots", a, b, c, sqr_eqn_solve(a, b, c));
}