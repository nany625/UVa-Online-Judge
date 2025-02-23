#include <stdio.h>
#define MAX_NUM 2000000

int phi[MAX_NUM + 1], sodf[MAX_NUM + 1];

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
    for(int n = 2; n <= MAX_NUM; ++n)
        sodf[n] = sodf[phi[n]] + 1;
    for(int n = 3; n <= MAX_NUM; ++n)
        sodf[n] += sodf[n - 1];
    int N;
    scanf("%d", &N);
    while(N--) {
        int m, n;
        scanf("%d %d", &m, &n);
        printf("%d\n", sodf[n] - sodf[m - 1]);
    }
	return 0;
}
