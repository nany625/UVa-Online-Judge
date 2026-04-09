#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_NUM 10000000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
int *primes, size = 1;

void eulerSieve() {
    primes = (int*)malloc(sizeof(int));
    primes[0] = 2;
    for(int n = 3; n <= MAX_NUM; n += 2) {
        if(!GET(n >> 1)) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 1, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            SET(temp >> 1);
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
