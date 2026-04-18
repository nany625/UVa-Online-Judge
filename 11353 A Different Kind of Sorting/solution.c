#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 2000000
#define MAX_CNT 20

int *primes, primeSize, pf[MAX_NUM + 1], **bucket, size[MAX_CNT + 1], order[MAX_NUM];

void eulerSieve() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(pf[n] == 0) {
            primes = (int*)realloc(primes, (primeSize + 1) * sizeof(int));
            primes[primeSize++] = n;
            pf[n] = 1;
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            pf[temp] = 1 + pf[n];
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    eulerSieve();
    bucket = (int**)malloc((MAX_CNT + 1) * sizeof(int*));
    for(int i = 0; i <= MAX_CNT; ++i)
        bucket[i] = NULL;
    for(int i = 1; i <= MAX_NUM; ++i) {
        bucket[pf[i]] = (int*)realloc(bucket[pf[i]], (size[pf[i]] + 1) * sizeof(int));
        bucket[pf[i]][size[pf[i]]++] = i;
    }
    int idx = 0;
    for(int i = 0; i <= MAX_CNT; ++i) {
        for(int j = 0; j < size[i]; ++j)
            order[idx++] = bucket[i][j];
    }
    int cases = 0, n;
    while(scanf("%d", &n) && n != 0)
        printf("Case %d: %d\n", ++cases, order[n - 1]);
    free(primes);
    for(int i = 0; i <= MAX_CNT; ++i)
        free(bucket[i]);
    free(bucket);
	return 0;
}
