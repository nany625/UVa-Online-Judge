#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    double PI = acos(-1), s, a;
    char str[4];
    while(scanf("%lf %lf %s", &s, &a, str) == 3) {
        if(str[0] == 'm')
            a /= 60;
        if(a > 180)
            a = 360 - a;
        printf("%.6f %.6f\n", (6440 + s) * PI * a / 180, sqrt(2 * pow(6440 + s, 2) * (1 - cos(a * PI / 180))));
    }
    return 0;
}
