#include <stdio.h>
//7_1

int main()
{
    int mas[5] = {1, 4, 6, 93, 12};

    int a;
    printf("a=");
    scanf("%i", &a);

    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (mas[i] < a)
        {
            cnt++;
        }
    }

    printf("there are %i elements less then %i", cnt, a);
}