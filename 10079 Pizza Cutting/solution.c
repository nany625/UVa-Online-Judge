#include <stdio.h>

int main() {
    long N;
    while(scanf("%ld", &N) && N >= 0)
        printf("%ld\n", ((1 + N) * N >> 1) + 1);
    return 0;
}
