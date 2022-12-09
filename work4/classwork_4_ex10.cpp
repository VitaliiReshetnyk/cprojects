#include <stdio.h>
void task10() {
	double a = 1;
	while ((1 + a) != 1) {
		a = a / 2;
	}
	printf("%.20lf", a);
}

int main()
{
    task10();
	 if ((1. + __FLT_MIN__) == 1.)
    {
        printf("True");
    }
}