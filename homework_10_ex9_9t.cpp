#include <stdio.h>
#include <stdlib.h>
//9_9t

/* Створення матриці n * m заповнення її нулями
*/
double** CreateMatrix(int r, int c )
{
    double **p;

    p = (double**)malloc(r * sizeof(double*)); // Виділення пам'яті під масив покажчиків на покажчики Дабл

    for (int i = 0; i < r; i++)
    {
        p[i] = (double*)malloc(c * sizeof(double)); // Виділення пам'яті під масив Даблов
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            p[i][j] = (double)i + (double)j / 10.0;
            //p[i][j] = 0.0;
        }
    }
    return p;
}

void DeleteMatrix(double **p, int r)
{
    for (int i = 0; i < r; i++)
    {
        free(p[i]);
    }
    free(p);
}

void InputMatrix(double **p, int r, int c)
{
    for (int j = 0; j < r; j++)
    {
        printf("Line N%i\n", j);
        for (int i = 0; i < c; i++)
        {
            scanf("%lf", &p[j][i]);
        }
    }    
}

void ShowMatrix(double** p, int r, int c)
{
    printf("Matrix %i x %i\n", r, c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%0.3lf ", p[i][j]);
        }
        printf("\n");
    }
}

double** ExpandMatrix(double **ptr, int r, int c, int index)
{
    static double *p;

    if (!(ptr = (double**)realloc(ptr, r * sizeof(double*))))
        printf("\nError_1\n");

    if (!(p = (double*)malloc(c * sizeof(double))))
        printf("\nError_2\n");

    for (int k = (r - 1); k > index; k--)
    {
        ptr[k] = ptr[k - 1];
    }
    
    ptr[index] = p;

    for(int i = 0; i < c; i++)
    {
        //ptr[index][i] = (double)index + (double)i / 10.0 + 0.001;
        //printf("%i,%i ", index, i);
        ptr[index][i] = 0.0;
    }

    return ptr;
}   

int main()
{   
    int rows, cols;
    double **pMatrix;

    printf("rows: ");
    scanf("%i", &rows);

    printf("cols: ");
    scanf("%i", &cols);

    pMatrix = CreateMatrix(rows, cols);

    ShowMatrix(pMatrix, rows, cols);

    //InputMatrix(pMatrix, rows, cols);

    //ShowMatrix(pMatrix, rows, cols);

    printf("\n");
    
    int index = 1;
    while (index <= rows)
    {
        pMatrix = ExpandMatrix(pMatrix, ++rows, cols, index);
        index += 3;
    }


    ShowMatrix(pMatrix, rows, cols);

    DeleteMatrix(pMatrix, rows);
}
