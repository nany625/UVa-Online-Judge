#include <stdio.h>

int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) == 2) {
        int ans = fac[n];
        while(k--) {
            int nk;
            scanf("%d", &nk);
            ans /= fac[nk];
        }
        printf("%d\n", ans);
    }
    return 0;
}
