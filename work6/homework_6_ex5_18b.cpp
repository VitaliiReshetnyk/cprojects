#include <stdio.h>
void func_b()
{
    unsigned k;
    printf("Print k:");
    scanf("%u", &k);
    int temp = 9;
    int digit = 1;
    while (k > temp * digit) {
        k -= temp * digit;
        temp *= 10;
        digit++;
    }
    int ans = 1;
    for (int i = 0; i < digit - 1; i++) {
        ans *= 10;
    }
    ans += (k - 1) / digit;
    k -= (k - 1) / digit * digit;
    int helper = 1;
    for (int i = 0; i < digit - k; i++) {
        helper *= 10;
    }
    printf("Ans = %i", ans / helper % 10);
}

int main()
{
    func_b();
}