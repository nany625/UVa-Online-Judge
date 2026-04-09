#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 31621
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
int *primes, size;

bool isPrime(int n) {
    if(n <= MAX_NUM) {
        if(n & 1)
            return !GET(n >> 1);
        return n == 2;
    }
    if(n & 1) {
        for(int i = 0; i < size; ++i) {
            if(n % primes[i] == 0)
                return false;
        }
        return true;
    }
    return false;
}

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

long bigMod(long a, int p, int mod) {
    if(p == 0)
        return 1 % mod;
    if(p == 1)
        return a % mod;
    long temp = bigMod(a, p >> 1, mod);
    if(p & 1)
        return temp * temp % mod * a % mod;
    return temp * temp % mod;
}

int main() {
    eulerSieve();
    int p;
    long a;
    while(scanf("%d %ld", &p, &a) && p != 0) {
        if(isPrime(p))
            puts("no");
        else
            puts(bigMod(a, p, p) == a ? "yes" : "no");
    }
    free(primes);
	return 0;
}
