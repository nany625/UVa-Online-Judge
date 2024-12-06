#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 10000000

bool isComposite[MAX_NUM + 1];
int *primes, size;

void eulerSieve() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(!isComposite[n]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

long solve(long n) {
    int limit = sqrt(n), count = 0;
    long max = 0;
    for(int i = 0; i < size && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0) {
            ++count;
            max = primes[i];
            do {
                n /= primes[i];
            } while(n % primes[i] == 0);
            limit = sqrt(n);
        }
    }
    if(n > 1) {
        ++count;
        max = n;
    }
    return count > 1 ? max : -1;
}

int main() {
    eulerSieve();
    long N;
    while(scanf("%ld", &N) && N != 0)
        printf("%ld\n", solve(labs(N)));
    free(primes);
    return 0;
}
