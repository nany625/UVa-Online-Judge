#include <stdio.h>

void pfCheck(int *n, int factor, int *count) {
    if(*n % factor == 0) {
        ++(*count);
        do {
            *n /= factor;
        } while(*n % factor == 0);
    }
}

int main() {
    int num;
    while(scanf("%d", &num) && num != 0) {
        int temp = num, factor = 3, pfCount = 0;
        pfCheck(&temp, 2, &pfCount);
        while(temp > 1) {
            pfCheck(&temp, factor, &pfCount);
            factor += 2;
        }
        printf("%d : %d\n", num, pfCount);
    }
    return 0;
}
