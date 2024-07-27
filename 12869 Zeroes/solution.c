#include <stdio.h>

int main() {
    long low, high;
    while(scanf("%ld %ld", &low, &high) && low != 0 && high != 0)
        printf("%ld\n", high / 5 - low / 5 + 1);
    return 0;
}
