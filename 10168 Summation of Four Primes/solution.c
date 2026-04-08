#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXN 9999993
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAXN >> 6) + 1];
int *primes, size;

void eulerSieve() {
    for(int n = 3; n <= MAXN; n += 2) {
        if(!GET(n >> 1)) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAXN; ++i) {
            SET(temp >> 1);
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    eulerSieve();
    int N;
    while(scanf("%d", &N) == 1) {
        if(N < 8)
            puts("Impossible.");
        else if(N & 1) {
            if(!GET(N - 6 >> 1))
                printf("2 2 2 %d\n", N - 6);
            else {
                N -= 5;
                int i = 0;
                while(GET(primes[i] >> 1) || GET(N - primes[i] >> 1))
                    ++i;
                printf("2 3 %d %d\n", primes[i], N - primes[i]);
            }
        } else {
            if(N == 8)
                puts("2 2 2 2");
            else {
                N -= 4;
                int i = 0;
                while(GET(primes[i] >> 1) || GET(N - primes[i] >> 1))
                    ++i;
                printf("2 2 %d %d\n", primes[i], N - primes[i]);
            }
        }
    }
    free(primes);
	return 0;
}
