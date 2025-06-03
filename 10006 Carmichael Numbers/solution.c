// #解法一(正規演算法)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXN 64999

bool isComposite[(MAXN >> 1) + 1];
int *primes, size;

void eulerSieve() {
    for(int n = 3; n <= MAXN; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAXN; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

long bigMod(long a, int n, int mod) {
    if(n == 0)
        return 1 % mod;
    if(n == 1)
        return a % mod;
    long temp = bigMod(a, n >> 1, mod);
    if(n & 1)
        return temp * temp % mod * a % mod;
    return temp * temp % mod;
}

bool isCarmichael(int n) {
    for(int a = 2; a < n; ++a) {
        if(bigMod(a, n, n) != a)
            return false;
    }
    return true;
}

int main() {
    eulerSieve();
    int n;
    while(scanf("%d", &n) && n != 0) {
        if(n & 1 && !isComposite[n >> 1])
            printf("%d is normal.\n", n);
        else {
            if(isCarmichael(n))
                printf("The number %d is a Carmichael number.\n", n);
            else
                printf("%d is normal.\n", n);
        }
    }
    free(primes);
	return 0;
}

// #解法二(捷徑)
#include <stdio.h>
#include <stdbool.h>
#define MAXN 64999

bool isCarmichael[MAXN + 1];
int ans[] = {
    561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341,
    41041, 46657, 52633, 62745, 63973
};

int main() {
    for(int i = 0; i < 15; ++i)
        isCarmichael[ans[i]] = true;
    int n;
    while(scanf("%d", &n) && n != 0) {
        if(isCarmichael[n])
            printf("The number %d is a Carmichael number.\n", n);
        else
            printf("%d is normal.\n", n);
    }
	return 0;
}
