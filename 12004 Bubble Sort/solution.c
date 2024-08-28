#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        long n;
        scanf("%ld", &n);
        long numerator = n * (n - 1);
        if(numerator & 3)
            printf("Case %d: %ld/2\n", i, numerator >> 1);
        else
            printf("Case %d: %ld\n", i, numerator >> 2);
    }
    return 0;
}
