#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 999999

bool isComposite[MAX_NUM + 1];
int *primes, size;

int main() {
    for(int i = 3; i <= MAX_NUM; i += 2) {
        if(!isComposite[i]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = i;
            if(i <= 999) {
                for(int j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
        }
    }
    int n;
    while(scanf("%d", &n) && n != 0) {
        int i = 0;
        while(isComposite[n - primes[i]])
            ++i;
        printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
    }
    free(primes);
	return 0;
}
