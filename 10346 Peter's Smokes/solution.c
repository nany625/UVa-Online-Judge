#include <stdio.h>

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) == 2) {
        int cigarettes = n;
        while(n / k) {
            cigarettes += n / k;
            n = n / k + n % k;
        }
        printf("%d\n", cigarettes);
    }
    return 0;
}
