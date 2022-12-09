#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//11_4

typedef struct
{
    unsigned int num;
    double x1;
    double y1;
    double x2;
    double y2;
}Rect;

void inputRect(Rect* x)
{
    printf("Input rect: ");
    
    scanf("%u", &(x->num));

    scanf("%lf %lf", &(x->x1), &(x->y1));

    scanf("%lf %lf", &(x->x2), &(x->y2));
}
void outputrect(const Rect* x)
{
    printf("Rectangle number: %u\n", x->num);
    printf("Vertix1(%lf, %lf)\n", x->x1, x->y1);
    printf("Vertix2(%lf, %lf)\n", x->x2, x->y1);
    printf("Vertix3(%lf, %lf)\n", x->x2, x->y2);
    printf("Vertix4(%lf, %lf)\n", x->x1, x->y2);
}
double areaRect(const Rect* x)
{
    //outputrect(x);
    return abs( (x->x1 - x->x2)*(x->y1 - x->y2));
}

int writerect(const char* fname)
{
    printf("n=");
    int n;
    scanf("%d", &n);
    Rect tmp;

    FILE* fp = fopen(fname, "wb");

    for (int i = 0; i < n; i++)
    {
        inputRect(&tmp);
        //outputrect(&tmp);
        //printf("area:%lf\n", areaRect(&tmp));
        fwrite(&tmp, 1, sizeof(tmp), fp);
    }
    fclose(fp);
    return n;
}

unsigned int numberMaxarea(const char* fname, unsigned n)
{
    FILE* fp = fopen(fname, "rb");
    Rect tmp;
    double maxArea = 0;
    unsigned ind = 0;
    unsigned i = 0;
    for(unsigned j = 0; j < n; j++)
    {
        fread(&tmp, 1, sizeof(tmp), fp);
        
        double area = areaRect(&tmp);
        if (area > maxArea)
        {
            maxArea = area;
            ind = tmp.num;
            //printf("ind%u\n", ind);
        }
        i++;
    }
    fclose(fp);
    printf("Max area is %lf\n", maxArea);
    return ind;
}

void viewRect(const char* fname, unsigned size)
{
    FILE* fp = fopen(fname, "rb");
    Rect aa;

    printf("____________\n");

    for(int j = 0; j < size; j++)
    {
        fread(&aa, 1, sizeof(aa), fp);
        outputrect(&aa);
    }
    fclose(fp);
}

void removeRect(const char* fname, unsigned n, unsigned *size)
{
    Rect aa;
    Rect* tmp = (Rect*)malloc(*size * sizeof(aa));
    FILE* fp = fopen(fname, "rb");


    //printf("____________\n");

    for(int j = 0; j < *size; j++)
    {
        fread((tmp + j), 1, sizeof(aa), fp);
        //outputrect((tmp + j));
    }
    fclose(fp);

    FILE* fg = fopen(fname, "wb");

    unsigned ttmp = *size;
    for(int j = 0; j < ttmp; j++)
    {
        if (tmp[j].num == n)
        {
            (*size)--;
            continue;
        }
        fwrite(&tmp[j], 1, sizeof(aa), fg);
    }
    
    fclose(fg);
    free(tmp);
}



//11_4

int main()
{
    char name[40];
    unsigned number_biggest;
    unsigned n;

    printf("name of file: ");
    scanf("%32s", &name);
    n = writerect(name);
    
    number_biggest = numberMaxarea(name, n);
    printf("Number of biggest rectangle %u\n", number_biggest);
    
    
    removeRect(name, number_biggest, &n);
    printf("This rectangle was removed");
    //viewRect(name, n);
}
