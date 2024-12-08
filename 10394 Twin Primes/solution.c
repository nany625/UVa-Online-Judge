#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 20000000

bool isComposite[(MAX_NUM >> 1) + 1];
int *primes, size, twinPrimes[100000], count = 1;

void eulerSieve() {
    for(int n = 5; count < 100000; n += 4) {
        if(!isComposite[n >> 1]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
        n += 2;
        if(!isComposite[n >> 1]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
        if(!isComposite[(n >> 1) - 1] && !isComposite[n >> 1])
            twinPrimes[count++] = n - 2;
    }
}

int main() {
    twinPrimes[0] = 3;
    eulerSieve();
    int S;
    while(scanf("%d", &S) == 1)
        printf("(%d, %d)\n", twinPrimes[S - 1], twinPrimes[S - 1] + 2);
    free(primes);
	return 0;
}
