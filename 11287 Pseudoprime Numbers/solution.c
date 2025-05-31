#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 31621

bool isComposite[(MAX_NUM >> 1) + 1];
int *primes, size;

bool isPrime(int n) {
    if(n <= MAX_NUM) {
        if(n & 1)
            return !isComposite[n >> 1];
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
        else {
            long ans = bigMod(a, p, p);
            puts(ans == a ? "yes" : "no");
        }
    }
    free(primes);
	return 0;
}
