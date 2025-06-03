#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 1000000

bool isComposite[(MAX_NUM >> 1) + 1];
int *primes, size = 1;

void eulerSieve() {
    primes = (int*)malloc(sizeof(int));
    primes[0] = 2;
    for(int n = 3; n <= MAX_NUM; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 1, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    eulerSieve();
    long n;
    while(scanf("%ld", &n) && n >= 0) {
        int limit = sqrt(n);
        for(int i = 0; i < size && primes[i] <= limit; ++i) {
            if(n % primes[i] == 0) {
                do {
                    printf("    %d\n", primes[i]);
                    n /= primes[i];
                } while(n % primes[i] == 0);
                limit = sqrt(n);
            }
        }
        if(n > 1)
            printf("    %ld\n", n);
        putchar('\n');
    }
    free(primes);
    return 0;
}
