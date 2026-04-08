#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_NUM 30000000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
int *primes, size;

void eulerSieve() {
    for(int n = 3; n <= MAX_NUM; n += 2) {
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
}

int main() {
    eulerSieve();
    long N;
    while(scanf("%ld", &N) == 1) {
        if(N == 0)
            puts("0");
        else {
            while((N & 1) == 0)
                N >>= 1;
            int count = 1, limit = sqrt(N);
            for(int i = 0; i < size && primes[i] <= limit; ++i) {
                if(N % primes[i] == 0) {
                    int term = 1;
                    do {
                        ++term;
                        N /= primes[i];
                    } while(N % primes[i] == 0);
                    count *= term;
                    limit = sqrt(N);
                }
            }
            if(N > 1)
                count <<= 1;
            printf("%d\n", count);
        }
    }
    free(primes);
    return 0;
}
