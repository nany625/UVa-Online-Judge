#include <stdio.h>

int josephus(int n, int k) {
    return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k, m;
    while(scanf("%d %d %d", &n, &k, &m) && n != 0)
        printf("%d\n", (josephus(n - 1, k) + m) % n + 1);
    return 0;
}
