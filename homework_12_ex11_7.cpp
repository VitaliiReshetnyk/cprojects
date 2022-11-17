#include <vector>
#include <stdio.h>
//11_7є

int read_fromn_file(const char *fname)
{
    FILE *fl = fopen(fname, "rb");
    if (fl == NULL)
    {
        printf("Fail open File %s\n", fname);
        return -1;
    }

    double temp;
    std::vector <double> a;

    do
    {
        fscanf(fl, "%lf ", &temp);
        a.push_back(temp);
    } while (!feof(fl));

    double min = a.at(0), max = a.at(0);
    for (double i: a)
    {
        if (min > i)
        {
            min = i;
        }
        if (max < i)
        {
            max = i;
        }
    }
    printf("Sum of min and max = %lf", min + max);

    fclose(fl);
    return 0;
}

int main()
{
    char name[50];
    printf("Input name of file:");
    scanf("%44s", &name);
    read_fromn_file(name);
}