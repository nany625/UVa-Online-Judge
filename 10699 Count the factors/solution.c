#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 1000

bool isComposite[(MAX_NUM >> 1) + 1];
short *primes;
int size = 1;

void eratosthenesSieve() {
    primes = (short*)malloc(sizeof(short));
    primes[0] = 2;
    for(short n = 3; n <= MAX_NUM; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = n;
            if(n <= 31) {
                for(int i = n * n; i <= MAX_NUM; i += n << 1)
                    isComposite[i >> 1] = true;
            }
        }
    }
}

int main() {
    eratosthenesSieve();
    int num;
    while(scanf("%d", &num) && num != 0) {
        printf("%d : ", num);
        short limit = sqrt(num);
        int count = 0;
        for(int i = 0; i < size && primes[i] <= limit; ++i) {
            if(num % primes[i] == 0) {
                ++count;
                do {
                    num /= primes[i];
                } while(num % primes[i] == 0);
                limit = sqrt(num);
            }
        }
        printf("%d\n", count + (num > 1));
    }
    free(primes);
    return 0;
}
