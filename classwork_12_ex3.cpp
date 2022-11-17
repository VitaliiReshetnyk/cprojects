#include <stdio.h>
#include <stdlib.h>
//11_1

void write_in_file(const char *fname, double *lst, int n)
{
    FILE *fl;
    fl = fopen(fname, "wb");

    for (int i =0; i < n; i++)
    {
        fprintf(fl, "%.2lf " , lst[i]);
    }

    fclose(fl);
}

void read_fromn_file(const char *fname, int n)
{
    FILE *fl;
    fl = fopen(fname, "rt");
    double temp;

    fscanf(fl, "%lf ", &temp);
    printf("%.2lf", temp);    

    for (int i = 1; i < n; i++)
    {
        fscanf(fl, "%lf ", &temp);
        printf(", %.2lf", temp);
    }

    printf("\n");
    fclose(fl);
}


int main()
{
    unsigned int n;
    double *array;

    printf("number of elemnts: ");
    scanf("%u", &n);

    array = (double*)malloc(n * sizeof(array));
    for (unsigned int i = 0; i < n; i++)
    {
        printf("a[%i]=", i+1);
        scanf("%lf", &array[i]);
    }
    char name[40];

    printf("Input name of file: ");
    scanf("%36s", &name);

    write_in_file(name, array, n);
    read_fromn_file(name, n);

    free(array);
}