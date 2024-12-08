#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 46340

bool isComposite[MAX_NUM + 1];
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
    int g;
    while(scanf("%d", &g) && g != 0) {
        printf("%d = ", g);
        bool firstFactor = true;
        if(g < 0) {
            fputs("-1", stdout);
            g *= -1;
            firstFactor = false;
        }
        int limit = sqrt(g);
        for(int i = 0; i < size && primes[i] <= limit; ++i) {
            if(g % primes[i] == 0) {
                do {
                    if(!firstFactor)
                        fputs(" x ", stdout);
                    printf("%d", primes[i]);
                    g /= primes[i];
                    firstFactor = false;
                } while(g % primes[i] == 0);
                limit = sqrt(g);
            }
        }
        if(g > 1) {
            if(!firstFactor)
                fputs(" x ", stdout);
            printf("%d\n", g);
        } else
            putchar('\n');
    }
    free(primes);
	return 0;
}