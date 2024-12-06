#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 20000000

bool isComposite[MAX_NUM + 1];
int *primes, size = 1, twinPrimes[100000], count = 1;

void eulerSieve() {
    for(int n = 5; count < 100000; n += 4) {
        if(!isComposite[n]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp] = true;
            if(n % primes[i] == 0)
                break;
        }
        n += 2;
        if(!isComposite[n]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp] = true;
            if(n % primes[i] == 0)
                break;
        }
        if(!isComposite[n - 2] && !isComposite[n])
            twinPrimes[count++] = n - 2;
    }
}

int main() {
    primes = (int*)malloc(sizeof(int));
    primes[0] = twinPrimes[0] = 3;
    eulerSieve();
    int S;
    while(scanf("%d", &S) == 1)
        printf("(%d, %d)\n", twinPrimes[S - 1], twinPrimes[S - 1] + 2);
    free(primes);
	return 0;
}
