/* 10.1, Комп. мат. 1, Решетник.
 * Тестові функції C проекту
*/

#include <stdio.h>
#include "NZ1_bitField.h"
#include <time.h>

void bitFieldTest()
{
    Product_st *Products = NULL;
    unsigned int quantity = 0;
    unsigned long int time = 0;
    int sel = 0;

    for (;;)
    {
        printf("\nBit field test. Please select...\n"
               "1. Read from file\n"
               "2. Read from console\n"
               "3. Out to console\n"
               "4. Out to file\n"
               "5. View presence and not EU standard\n"
               "6. Read from file and write file for time test\n"
               "0. Back previous menu\n");

        scanf("%i", &sel);

        switch (sel)
        {
        case 0:
            return;
        case 1:
            quantity = in_file(&Products);
            break;
        case 2:
            quantity = in_console(&Products);
            break;
        case 3:
            if (quantity)
            {
                out_console(Products, quantity);
            }
            else
            {
                printf ("Do an input first!\n");
            }
            quantity = 0; // Функція виводу після відпрацювання, вивільняє пам'ять
            break;
        case 4:
            if (quantity)
            {
                out_file(Products, quantity);
            }
            else
            {
                printf ("Do an input first!\n");
            }
            quantity = 0; // Функція виводу після відпрацювання, вивільняє пам'ять
            break;
        case 5:
            if (quantity)
            {
                viewNotEU(Products, quantity);
            }
            else
            {
                printf ("Do an input first!\n");
            }
            quantity = 0; // Функція виводу після відпрацювання, вивільняє пам'ять
            break;
        case 6:
            time = clock(); // Часова мітка
            quantity = in_file(&Products);
            out_file(Products, quantity);
            printf("RunTime = %.3f s\n", (float)(clock() - time) / CLOCKS_PER_SEC); // Визначення та вивід часу виконання
            quantity = 0; // Функція виводу після відпрацювання, вивільняє пам'ять
            break;
        }
    }
}
