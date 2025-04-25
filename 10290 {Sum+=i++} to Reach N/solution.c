#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 750000

bool isComposite[(MAX_NUM >> 1) + 1];
int *primes, size;

void eulerSieve() {
    for(int n = 3; n <= MAX_NUM; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    eulerSieve();
    long N;
    while(scanf("%ld", &N) == 1) {
        while((N & 1) == 0)
            N >>= 1;
        int count = 1;
        for(int i = 0; i < size && N > 1; ++i) {
            int term = 0;
            while(N % primes[i] == 0) {
                ++term;
                N /= primes[i];
            }
            count *= (term + 1);
        }
        if(N > 1)
            count <<= 1;
        printf("%d\n", count);
    }
    free(primes);
    return 0;
}
