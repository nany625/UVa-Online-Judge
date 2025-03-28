#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    while(scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        if(a + b + c == 0)
            puts("The radius of the round table is: 0.000");
        else {
            double s = (a + b + c) / 2;
            double area = sqrt(s * (s - a) * (s - b) * (s - c));
            printf("The radius of the round table is: %.3f\n", area * 2 / (a + b + c));
        }
    }
    return 0;
}
