#include <stdio.h>
#include <stdlib.h>

int humbleNumbers[5842], size = 0;

int compare(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int main() {
    long temp = 1;
    while(temp <= 2000000000 && size < 5842) {
        long a = 1;
        while(temp <= 2000000000 && size < 5842) {
            long b = 1;
            while(temp <= 2000000000 && size < 5842) {
                long c = 1;
                while(temp <= 2000000000 && size < 5842) {
                    humbleNumbers[size++] = temp;
                    temp *= 7;
                    c *= 7;
                }
                temp /= c;
                temp *= 5;
                b *= 5;
            }
            temp /= b;
            temp *= 3;
            a *= 3;
        }
        temp /= a;
        temp <<= 1;
    }
    qsort(humbleNumbers, 5842, sizeof(int), compare);
    int n;
    while(scanf("%d", &n) && n != 0) {
        if(n % 100 >= 11 && n % 100 <= 13)
            printf("The %dth humble number is %d.\n", n, humbleNumbers[n - 1]);
        else if(n % 10 == 1)
            printf("The %dst humble number is %d.\n", n, humbleNumbers[n - 1]);
        else if(n % 10 == 2)
            printf("The %dnd humble number is %d.\n", n, humbleNumbers[n - 1]);
        else if(n % 10 == 3)
            printf("The %drd humble number is %d.\n", n, humbleNumbers[n - 1]);
        else
            printf("The %dth humble number is %d.\n", n, humbleNumbers[n - 1]);
    }
    return 0;
}
