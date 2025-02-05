// #解法一
#include <stdio.h>

int josephus(int n, int k) {
    int ans = 0;
    for(int i = 2; i <= n; ++i)
        ans = (ans + k) % i;
    return ans;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for(int i = 1; i <= cases; ++i) {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", i, josephus(n, k) + 1);
    }
    return 0;
}

// #解法二
#include <stdio.h>

int josephus(int n, int k) {
    return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for(int i = 1; i <= cases; ++i) {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", i, josephus(n, k) + 1);
    }
    return 0;
}
