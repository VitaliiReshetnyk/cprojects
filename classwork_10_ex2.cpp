#include <stdio.h>
#include <math.h>
#define N 100
//9_2

int func(int a[N])
{
    int temp;
    int i = 0;
    for (; i < N; i++)
    {
        printf("a[%i]=", i);
        scanf("%i", &temp);
        if (temp == 0)
        {
            break;
        }
        a[i] = temp;
    }
    return i;
}

int main()
{   
    int a[N];
    int i = func(a);
    printf("Number of elements: %i\n", i);
    double temp;
    int root2 = 0, root3 = 0;
    for (int j = 0; j < i; j++)
    {
        temp = sqrt((double)fabs(a[j]));
        if (((int)temp*(int)temp)==a[j])
        {
            root2++;
        }
        temp = cbrt((double)a[j]);
        if (((int)temp*(int)temp*(int)temp)==a[j])
        {
            root3++;
        }
    }
    printf("Number of squares: %i\n", root2);
    printf("Number of cubes: %i\n", root3);
}