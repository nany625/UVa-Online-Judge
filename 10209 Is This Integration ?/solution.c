#include <stdio.h>
#include <math.h>
#define PI (2.0 * acos(0.0))

int main() {
    double a;
    while(scanf("%lf", &a) == 1)
        printf("%.3f %.3f %.3f\n", a * a * (PI / 3 + 1 - sqrt(3.0)), 4 * a * a * (PI / 12 - 1 + sqrt(3.0) / 2), 4 * a * a * (-PI / 6 + 1 - sqrt(3.0) / 4));
    return 0;
}
