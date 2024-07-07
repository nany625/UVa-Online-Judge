#include <stdio.h>
#include <math.h>

int main() {
    double L, W, eps = 1e-6;
    while(scanf("%lf %lf", &L, &W) == 2)
        printf("%.3f 0.000 %.3f\n", (L + W - sqrt(L * L + W * W - L * W)) / 6, (L > W ? W : L) / 2 + eps);
    return 0;
}
