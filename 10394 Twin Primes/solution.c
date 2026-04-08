#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 20000000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
int *primes, size, twinPrimes[100000] = {3}, count = 1;

void solve(int n) {
    if(!GET(n >> 1)) {
        primes = (int*)realloc(primes, (size + 1) * sizeof(int));
        primes[size++] = n;
    }
    for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
        SET(temp >> 1);
        if(n % primes[i] == 0)
            break;
    }
}

void eulerSieve() {
    for(int n = 5; count < 100000; n += 6) {
        solve(n);
        solve(n + 2);
        if(!GET(n >> 1) && !GET((n >> 1) + 1))
            twinPrimes[count++] = n;
    }
}

int main() {
    eulerSieve();
    int S;
    while(scanf("%d", &S) == 1)
        printf("(%d, %d)\n", twinPrimes[S - 1], twinPrimes[S - 1] + 2);
    free(primes);
	return 0;
}
