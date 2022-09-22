#include <stdio.h>
#include <math.h>
float heron (float a, float b, float c)
{
    float p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
float striangle()
{
    float x1,y1,x2,y2,x3,y3;
    printf("Point A:\n");
    scanf("%f %f",&x1,&y1);
    printf("Point B:\n");
    scanf("%f %f",&x2,&y2);
    printf("Point C:\n");
    scanf("%f %f",&x3,&y3);
    //float S = 0.5*abs((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3));
    float S = heron(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)),sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)),sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)));
    return S;
}
int main()
{
    float S = striangle();
    printf("%f",S);
}