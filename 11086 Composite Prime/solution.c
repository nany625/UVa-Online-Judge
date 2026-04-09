#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 524288
#define MAX_N 1048576
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1], isCompositePrime[(MAX_N >> 5) + 1];
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

int main() {
    eulerSieve();
    for(int i = 0; i < size; ++i) {
        for(int j = 0, temp; j < size && (temp = primes[i] * primes[j]) <= MAX_N; ++j)
            isCompositePrime[temp >> 5] |= 1u << (temp & 31);
    }
    int N;
    while(scanf("%d", &N) == 1) {
        int count = 0;
        while(N--) {
            int num;
            scanf("%d", &num);
            if(isCompositePrime[num >> 5] & (1u << (num & 31)))
                ++count;
        }
        printf("%d\n", count);
    }
    free(primes);
    return 0;
}
