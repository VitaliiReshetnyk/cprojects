/* 10.1, Комп. мат. 1, Решетник.
 * Файл прототипів
*/

#ifndef NZ1_BITFIELD_H
#define NZ1_BITFIELD_H

#define PRODUCT_NAME_MAX 32
#define COUNTRY_NAME_MAX 32

typedef struct
{
    char product_name[PRODUCT_NAME_MAX];
    char country_name[COUNTRY_NAME_MAX];
    float cost;
    unsigned int presence:1;
    unsigned int standard:1;
    unsigned int best:1;
} Product_st;

extern void formatScanf(char *a, unsigned int n);
extern unsigned int in_console(Product_st **r);
extern void out_console(Product_st *r, unsigned int quantity);
extern void viewNotEU(Product_st *r, unsigned int quantity);
extern unsigned int in_file(Product_st **r);
extern void out_file(Product_st *r, unsigned int quantity);

#endif // NZ1_BITFIELD_H
