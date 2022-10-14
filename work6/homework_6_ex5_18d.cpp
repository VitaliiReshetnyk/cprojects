#include <stdio.h>
int func_help_d(int k)
{
    if (k == 1)
    {
        return 0;
    }
    if (k == 2)
    {
        return 1;
    }
    return func_help_d(k - 1) + func_help_d(k - 2);
}
int lenint(int k)
{
    if (k == 0) return 1;
    int ans = 0;
    while (k)
    {
        k /= 10;
        ans++;
    }
    return ans;
}

int func_d(unsigned k)
{
    int counter = 1;
    int temp1, len;
    int help;
    while (k > 0)
    {
        temp1 = func_help_d(counter);
        len = lenint(temp1);
        if (k > len)
        {
            counter++;
            k -= len;
        }
        else
        {
            if (k == len)
            {
                return temp1 % 10;
            }
            else
            {
                help = len - k;
                for (int dz = 1; dz <= help; dz++)
                {
                    temp1 /= 10;
                }
                return temp1 % 10;
            }
        }
    }
    return 0;
}

int main()
{
    unsigned k;
    printf("Print k:");
    scanf("%u", &k);    
    printf("Ans = %i\n", func_d(k));
}