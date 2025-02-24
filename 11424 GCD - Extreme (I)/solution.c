#include <stdio.h>
#define MAX_NUM 200000

int phi[MAX_NUM + 1];
long ans[MAX_NUM + 1];

void eratosthenesSieve() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(phi[n] == n) {
            for(int i = n; i <= MAX_NUM; i += n)
                phi[i] -= phi[i] / n;
        }
    }
}

int main() {
    for(int n = 2; n <= MAX_NUM; ++n)
        phi[n] = n;
    eratosthenesSieve();
    for(int n = 2; n <= MAX_NUM; ++n) {
        for(int i = n << 1; i <= MAX_NUM; i += n)
            ans[i] += n * phi[i / n];
        ans[n] += ans[n - 1] + phi[n];
    }
    int N;
    while(scanf("%d", &N) && N != 0)
        printf("%ld\n", ans[N]);
}
