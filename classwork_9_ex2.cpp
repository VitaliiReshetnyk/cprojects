#include <stdio.h>
//7_2

int main()
{
    int mas[4] = {5, 112, 4, 3};
    for (int i = sizeof(mas)/sizeof(mas[0])-1; i >= 0; i--)
    {
        printf("%i ", mas[i]);
    }
}