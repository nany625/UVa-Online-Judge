#include <stdio.h>
#define MAXN 500

int phi[MAXN + 1], ans[MAXN + 1];

void eratosthenesSieve() {
    for(int n = 2; n <= MAXN; ++n) {
        if(phi[n] == n) {
            for(int i = n; i <= MAXN; i += n)
                phi[i] -= phi[i] / n;
        }
    }
}

int main() {
    for(int n = 2; n <= MAXN; ++n)
        phi[n] = n;
    eratosthenesSieve();
    for(int n = 2; n <= MAXN; ++n) {
        for(int i = n << 1; i <= MAXN; i += n)
            ans[i] += n * phi[i / n];
        ans[n] += ans[n - 1] + phi[n];
    }
    int N;
    while(scanf("%d", &N) && N != 0)
        printf("%d\n", ans[N]);
}
