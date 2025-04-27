#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000000

int pfCount[MAX_NUM + 1], mu[MAX_NUM + 1] = {0, 1}, M[MAX_NUM + 1], *primes, size;

void eulerSieve() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(pfCount[n] == 0) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
            pfCount[n] = 1;
            mu[n] = -1;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            pfCount[temp] = pfCount[primes[i]] + pfCount[n];
            if(n % primes[i] == 0)
                break;
            else if(mu[n] != 0)
                mu[temp] = pfCount[temp] & 1 ? -1 : 1;
        }
    }
}

int main() {
    eulerSieve();
    for(int n = 1; n <= MAX_NUM; ++n)
        M[n] = M[n - 1] + mu[n];
    int N;
    while(scanf("%d", &N) && N != 0)
        printf("%8d%8d%8d\n", N, mu[N], M[N]);
    free(primes);
	return 0;
}
