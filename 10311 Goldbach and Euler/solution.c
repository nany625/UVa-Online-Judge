#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000000
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
    int n;
    while(scanf("%d", &n) == 1) {
        if(n <= 4)
            printf("%d is not the sum of two primes!\n", n);
        else {
            if(n & 1) {
                if(GET(n - 2 >> 1))
                    printf("%d is not the sum of two primes!\n", n);
                else
                    printf("%d is the sum of 2 and %d.\n", n, n - 2);
            } else {
                int temp = n - 1 >> 1;
                temp -= !(temp & 1);
                while(temp >= 3 && (GET(temp >> 1) || GET(n - temp >> 1)))
                    temp -= 2;
                if(temp >= 3)
                    printf("%d is the sum of %d and %d.\n", n, temp, n - temp);
                else
                    printf("%d is not the sum of two primes!\n", n);
            }
        }
    }
    free(primes);
    return 0;
}
