#include <stdio.h>
long long three_n_plus_one(long long n)
{
    if (n % 2)
    {
        return n * 3 + 1;
    }
    else
    {
        return n/2;
    }
}

int main()
{
    long long number = 0, steps = 0, temp, counter;
    for (long long i = 1; i <= 1000; i++)
    {
        temp = i;
        counter = 0;
        while (temp != 1)
        {
            counter += 1;
            temp = three_n_plus_one(temp);
        }
        printf("Number = %llu; steps to become 1: %llu\n", i, counter);
        if (steps < counter) 
        {
            steps = counter;
            number = i;
        }
    }
    printf("\n\nMAX\nNumber = %llu; steps to become 1: %llu", number, steps);
}