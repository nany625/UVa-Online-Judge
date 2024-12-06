#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 524288
#define MAX_N 1048576

bool isComposite[MAX_NUM + 1], isCompositePrime[MAX_N + 1];
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

int main() {
    eulerSieve();
    for(int i = 0; i < size; ++i) {
        for(int j = 0, temp; j < size && (temp = primes[i] * primes[j]) <= MAX_N; ++j)
            isCompositePrime[temp] = true;
    }
    int N;
    while(scanf("%d", &N) == 1) {
        int count = 0;
        while(N--) {
            int num;
            scanf("%d", &num);
            count += isCompositePrime[num];
        }
        printf("%d\n", count);
    }
    free(primes);
    return 0;
}
