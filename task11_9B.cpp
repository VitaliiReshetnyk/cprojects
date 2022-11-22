#include <stdio.h>
#include <stdlib.h>
//11_9B

int writeInG(const char *F, const char *G)
{
    FILE* fp;
    if((fp=fopen(F, "r"))==NULL) {
    printf ("Cannot open file.\n");
    return -1;
    }
    unsigned counter = 0;
    int pos = 0;
    int neg = 0;
    int temp;
    while(!feof(fp))
    {
        fscanf(fp, "%*i", &temp);
        if (temp > 0)
        {
            pos++;
        }
        if (temp < 0)
        {
            neg++;
        }
        counter++;
    }
    printf("Numbers: %u\n", counter);
    if (pos!=neg)
    {
        fclose(fp);
        printf("Not equal quantity of integtegers!!\n");
        return 2;        
    }
    fclose(fp);


    if((fp=fopen(F, "r"))==NULL) {
    printf ("Cannot open file.\n");
    return -1;
    }
    int *arraypos = (int*)malloc(((counter / 2) + 1) * sizeof(int)); int poscount = 0;
    int *arrayneg = (int*)malloc(((counter / 2) + 1) * sizeof(int)); int negcount = 0;
    int *arrayother=(int*)malloc(((counter / 2) + 1) * sizeof(int)); int othcount = 0;

    for (int i = 0; i < counter; i++)
    {
        fscanf(fp, "%i", &temp);
        if (temp > 0)
        {
            arraypos[poscount] = temp;
            poscount++;
            continue;
        }
        if (temp < 0)
        {
            arrayneg[negcount] = temp;
            negcount++;
            continue;
        }
        arrayother[othcount] = temp;
        othcount++;
    }
    fclose(fp);

    if((fp=fopen(G, "wt"))==NULL) {
    printf ("Cannot open file.\n");
    return -1;
    }

    int poscount1 = 0;
    int negcount1 = 0;
    int othcount1 = 0;
    
    for (int j = 0; j < (counter/4)*4; j++)
    {
        if ((j % 4 < 2) && (poscount1 < poscount))
        {
            fprintf(fp, "%i\n", arraypos[poscount1]);
            poscount1++;
            continue;
        }
        if ((j % 4 >= 2) && (negcount1 < negcount))
        {
            fprintf(fp, "%i\n", arrayneg[negcount1]);
            negcount1++;
            continue;
        }
    }

    for (;poscount1 < poscount; poscount1++)
    {
        printf("%i\n", arraypos[poscount1]);
    }
    for (;negcount1 < negcount; negcount1++)
    {
        printf("%i\n", arrayneg[negcount1]);
    }
    for (;othcount1 < othcount; othcount1++)
    {
        printf("%i\n", arrayother[othcount1]);
    }

    fclose(fp);
    free(arraypos);
    free(arrayneg);
    free(arrayother);
    return 0;
}

int main()
{
    writeInG("F.txt", "G.txt");
}