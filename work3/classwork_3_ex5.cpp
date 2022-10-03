#include <stdio.h>

int main()
{
	int a, b;
	printf("Input two variables:\n");
	scanf_s("%d %d", &a, &b);

	if (a > b) {
		printf("First number is bigger than second!\n");
		printf("Max is: %d\n", a);
		printf("Min is: %d\n", b);
	}
	else if (b > a) {
		printf("Second number is bigger than first!\n");
		printf("Max is: %d\n", b);
		printf("Min is: %d\n", a);
	}
	else {
		printf("Two number is equal to each other!\n");
	}
}
