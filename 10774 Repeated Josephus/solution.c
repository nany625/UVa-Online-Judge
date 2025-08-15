#include <stdio.h>

int josephus(int n, int k) {
    return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for(int i = 1; i <= cases; ++i) {
        int n;
        scanf("%d", &n);
        int rep = 0, survivor;
        while(n != (survivor = josephus(n, 2) + 1)) {
            n = survivor;
            ++rep;
        }
        printf("Case %d: %d %d\n", i, rep, n);
    }
    return 0;
}
