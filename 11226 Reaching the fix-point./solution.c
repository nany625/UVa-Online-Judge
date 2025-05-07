#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 500000

int *primes, size, sopf[MAX_NUM + 1], lsopf[MAX_NUM + 1];

void eulerSieve() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(sopf[n] == 0) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
            sopf[n] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            sopf[temp] = sopf[primes[i]] + sopf[n];
            if(n % primes[i] == 0)
                break;
        }
        lsopf[n] = sopf[n] == n ? 1 : 1 + lsopf[sopf[n]];
    }
}

int main() {
    eulerSieve();
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int n, m;
        scanf("%d %d", &n, &m);
        if(n > m) {
            int temp = n;
            n = m;
            m = temp;
        }
        int max = 0;
        for(int j = n; j <= m; ++j)
            max = max > lsopf[j] ? max : lsopf[j];
        printf("Case #%d:\n%d\n", i, max);
    }
    free(primes);
	return 0;
}
