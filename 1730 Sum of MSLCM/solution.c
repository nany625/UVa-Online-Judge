#include <stdio.h>
#define MAXN 20000000

long ans[MAXN + 1];

void init() {
    for(int n = 2; n <= MAXN; ++n) {
        for(int i = n; i <= MAXN; i += n)
            ans[i] += n;
    }
    for(int n = 3; n <= MAXN; ++n)
        ans[n] += ans[n - 1];
}

int main() {
    init();
    int N;
    while(scanf("%d", &N) && N != 0)
        printf("%ld\n", ans[N] + N - 1);
    return 0;
}
