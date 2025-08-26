#include <stdio.h>
#include <math.h>

int main() {
    long i;
    while(scanf("%ld", &i) == 1) {
        long n = ceil((1 + sqrt((i << 3) + 1)) / 2), denominator = i - ((n - 1) * (n - 2) >> 1);
        printf("%ld/%ld\n", n - denominator, denominator);
    }
    return 0;
}
