#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 999995

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
    int n;
    while(scanf("%d", &n) && n != 0) {
        int i = 0;
        while(isComposite[n - primes[i] >> 1])
            ++i;
        printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
    }
    free(primes);
	return 0;
}
