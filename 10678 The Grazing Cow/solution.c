#include <stdio.h>
#include <math.h>

int main() {
    double PI = acos(-1);
    int N;
    scanf("%d", &N);
    while(N--) {
        double D, L;
        scanf("%lf %lf", &D, &L);
        printf("%.3f\n", L * sqrt(L * L - D * D) * PI / 4);
    }
    return 0;
}
