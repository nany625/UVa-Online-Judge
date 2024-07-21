#include <stdio.h>
#include <math.h>

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) == 2)
        printf("%d\n", n + (int)floor((n - k) / (k - 1.0)) + 1);
    return 0;
}
