#include <stdio.h>
#include <math.h>

int main() {
    double PI = acos(-1), a;
    while(scanf("%lf", &a) == 1)
        printf("%.3f %.3f %.3f\n", a * a * (PI / 3 + 1 - sqrt(3)), 4 * a * a * (PI / 12 - 1 + sqrt(3) / 2), 4 * a * a * (-PI / 6 + 1 - sqrt(3) / 4));
    return 0;
}
