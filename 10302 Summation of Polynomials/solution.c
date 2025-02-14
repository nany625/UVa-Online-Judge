#include <stdio.h>

int main() {
    long x;
    while(scanf("%ld", &x) == 1)
        printf("%ld\n", (x + 1) * (x + 1) * x * x >> 2);
    return 0;
}
