#include <stdio.h>>
#include <math.h>

int main() {
    int S;
    long D;
    while(scanf("%d %ld", &S, &D) == 2)
        printf("%d\n", (int)ceil((-1 + sqrt(1 + 4 * (S * S - S + 2 * D))) / 2));
    return 0;
}
