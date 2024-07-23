#include <stdio.h>
#include <math.h>
#define EPS 1e-4

int main() {
    double L, W;
    while(scanf("%lf %lf", &L, &W) == 2)
        printf("%.3f 0.000 %.3f\n", (L + W - sqrt(L * L + W * W - L * W)) / 6, (L > W ? W : L) / 2 + EPS);
    return 0;
}
