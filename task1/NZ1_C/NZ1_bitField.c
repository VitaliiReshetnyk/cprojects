/* 10.1, Комп. мат. 1, Решетник.
   Реалізація функцій вводу та виводу
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NZ1_bitField.h"

/* Введення бітового значенн 0 або 1 з перевіркою на коректність
*/
unsigned int in_bit(char *s)
{
    unsigned int t = 0;

    do
    {
        printf("%s\n", s);
        if (!scanf("%u", &t))
        {
            scanf("%*s"); // Нема розпізнаних. Очищуємо рядок
            continue;
        }
    } while (t > 1); // Дозволено вводити тільки 0 та 1
    
    return t;
}

/* Виділяє пам'ять під масив структур продуктів
   Повертае кількість продуктів, або 0
   у разі неможливості виділення пам'яті
*/
unsigned int in_console(Product_st **r)
{
    unsigned int quantity = 0;
    Product_st *p;

    printf("Product quantity: ");
    scanf("%u", &quantity);
    
    p = (Product_st*)malloc(sizeof(Product_st) * quantity);
    if (p == NULL)
        return 0; // Помилка виділення пам'яті

    *r = p; // Переданий вказівник на вказівник у якості аргументу функції, тепер вказує на виділену пам'ять

    for (unsigned int i = 0; i < quantity; i++)
    {
        printf("Product %i:\n", i + 1);

        printf("Name:\n");
        scanf("%30s", p[i].product_name); // 30 - Обмеження рядка вводу за довжиною (Захист вводу)

        printf("Country:\n");
        scanf("%30s", p[i].country_name);

        do
        {
            printf("Cost:\n");
            if (!scanf("%f", &p[i].cost))
            {
                scanf("%*s"); // Стирання некоректних данных буферу вводу
                continue;
            }
        } while (p[i].cost < 0.0);
        
        p[i].presence = in_bit("Presence:");
        p[i].standard = in_bit("Standard:");
        p[i].best     = in_bit("Best:");
    }
    return quantity;
}

unsigned int in_file(Product_st **r)
{
    unsigned int quantity = 0;
    unsigned int t = 0;
    FILE *fp;
    Product_st *p;

    if ((fp = fopen("shop.txt", "rt")) == NULL)
        return 0; // Помилка відкриття файлу

    fscanf(fp, "Quantity: %u%*c%*c", &quantity); // І пропуск двох переводів рядків

    p = (Product_st*)malloc(sizeof(Product_st) * quantity);
    if (p == NULL)
        return 0; // Помилка виділення пам'яті

    *r = p;

    for (unsigned int i = 0; i < quantity; i++)
    {
        fscanf(fp,    "Name: %30s%*c", p[i].product_name);
        fscanf(fp, "Country: %30s%*c", p[i].country_name);
        fscanf(fp,      "Cost: %f%*c", &p[i].cost);
        fscanf(fp,  "Presence: %u%*c", &t);                // Бітові поля не мають власної адреси, тому, проміжна змінна
        p[i].presence = t;
        fscanf(fp,  "Standard: %u%*c", &t);
        p[i].standard = t;
        fscanf(fp,   "Best: %u%*c%*c", &t);
        p[i].best = t;
    }

    if (fclose(fp))
        return 0; // Помилка закриття файлу

    return quantity;
}

void out_console(Product_st *r, unsigned int quantity)
{
    printf("Quantity: %u\n\n", quantity);
    for (unsigned int i = 0; i < quantity; i++)
    {
        printf("    Name: %s\n", r[i].product_name);
        printf(" Country: %s\n", r[i].country_name);
        printf("    Cost: %.2f\n", r[i].cost); // Округлення ціни до сотих
        printf("Presence: %i\n", r[i].presence);
        printf("Standard: %i\n", r[i].standard);
        printf("    Best: %i\n\n", r[i].best);
    }
    free(r);
}

void viewNotEU(Product_st *r, unsigned int quantity)
{
    for (unsigned int i = 0; i < quantity; i++)
    {
        if(r[i].presence && !r[i].standard)
        {
            printf("    Name: %s\n",   r[i].product_name);
            printf(" Country: %s\n",   r[i].country_name);
            printf("    Cost: %.2f\n", r[i].cost);
            printf("Presence: %i\n",   r[i].presence);
            printf("Standard: %i\n",   r[i].standard);
            printf("    Best: %i\n\n", r[i].best);
        }
    }
    free(r);
}

void out_file(Product_st *r, unsigned int quantity)
{
    FILE *fp;

    if ((fp = fopen("out.txt", "wt")) == NULL)
        return; // Помилка відкриття файлу

    fprintf(fp, "Quantity %u:\n\n", quantity);
    for (unsigned int i = 0; i < quantity; i++)
    {
        fprintf(fp,     "Name: %s\n",   r[i].product_name);
        fprintf(fp,  "Country: %s\n",   r[i].country_name);
        fprintf(fp,     "Cost: %.2f\n", r[i].cost);         // Округлення ціни до сотих
        fprintf(fp, "Presence: %i\n",   r[i].presence);
        fprintf(fp, "Standard: %i\n",   r[i].standard);
        fprintf(fp,     "Best: %i\n", r[i].best);
    }
    free(r);
    fclose(fp);
}
