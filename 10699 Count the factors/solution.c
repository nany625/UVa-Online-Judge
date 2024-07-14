#include <stdio.h>
#include <math.h>

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
        printf("%d : ", num);
        int limit = sqrt(num), factor = 3, pfCount = 0;
        pfCheck(&num, 2, &pfCount);
        while(factor <= limit) {
            pfCheck(&num, factor, &pfCount);
            factor += 2;
        }
        if(num > 1)
            ++pfCount;
        printf("%d\n", pfCount);
    }
    return 0;
}
