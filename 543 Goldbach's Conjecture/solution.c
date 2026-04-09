#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 999995
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
    int n;
    while(scanf("%d", &n) && n != 0) {
        int i = 0;
        while(GET(n - primes[i] >> 1))
            ++i;
        printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
    }
    free(primes);
	return 0;
}
