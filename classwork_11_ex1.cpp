#include <stdio.h>
#include <stdlib.h>
//10_1

struct my_time
{
    unsigned num;
    unsigned month;
    unsigned year;
};

typedef struct
{
    char col;
    int row;
} Field;

struct point
{
    double x;
    double y;
};

struct rectangle
{
    struct point vertex1;
    struct point vertex2;
};

struct polynom
{
    unsigned a;
    double* b;
};

struct my_time my_time_input()
{
    unsigned num, month, year;
    printf("Number:");
    scanf("%u", &num);
    printf("Month:");
    scanf("%u", &month);
    printf("Year:");
    scanf("%u", &year);
    scanf("%*c");
    return my_time{num, month, year};
}

void my_time_print(struct my_time a)
{
    printf("Number:%u\n", a.num);
    printf("Month:%u\n", a.month);
    printf("Year:%u\n", a.year);
}



Field field_input()
{
    Field t;
    printf("ColRow:");
    scanf("%c%i", &t.col, &t.row);
    scanf("%*c");//для уникнення передавання переводу стрічки
    return t;
}

void field_print(const Field x)
{
    printf("%c:%u\n", x.col, x.row);
}



struct point point_input()
{
    double x, y;
    printf("X:");
    scanf("%lf", &x);
    printf("Y:");
    scanf("%lf", &y);
    scanf("%*c");
    return point{x, y};
}

struct rectangle rectangle_input()
{
    printf("Point1\n");
    struct point pnt1 = point_input();
    printf("Point2\n");
    struct point pnt2 = point_input();
    return rectangle{pnt1, pnt2};
}

void rectangle_print(struct rectangle a)
{
    printf("Point1: (%lf, %lf)\n", a.vertex1.x, a.vertex1.y);
    printf("Point2: (%lf, %lf)\n", a.vertex1.x, a.vertex2.y);
    printf("Point3: (%lf, %lf)\n", a.vertex2.x, a.vertex2.y);
    printf("Point4: (%lf, %lf)\n", a.vertex2.x, a.vertex1.y);
}



struct polynom polynom_input()
{
    unsigned a;
    printf("Order:");
    scanf("%u", &a);
    double *b;
    if (!(b = (double*)malloc((a + 1) * sizeof(b))))
    {
        printf("Error: can`t allocate memmory\n");
    }
    else
    {
        for (int i = 0; i <= a; i++)
        {
            printf("a%i=", i);
            scanf("%lf", (b + i));
        }
        scanf("%*c");
        return polynom{a, b};
    }
}

void polynom_print(struct polynom a)
{
    for (int i = a.a; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%lf", a.b[0]);
        }
        else
        {
            printf("%lf*x^%i + ", a.b[i], i);
        }
    }
    printf("\n");
}

void polynom_del(struct polynom a)
{
    free(a.b);
}

int main()
{
    struct my_time tm1 = my_time_input(); printf("\n");
    my_time_print(tm1);
    printf("________________\n");
    
    Field fld1 = field_input(); printf("\n");
    field_print(fld1);
    printf("________________\n");

    struct rectangle rctngl1 = rectangle_input(); printf("\n");
    rectangle_print(rctngl1);
    printf("________________\n");

    struct polynom plnm1 = polynom_input(); printf("\n");
    polynom_print(plnm1);
    polynom_del(plnm1);
}
