#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_NUM 46339
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
int *primes, size = 1;

void eulerSieve() {
    primes = (int*)malloc(sizeof(int));
    primes[0] = 2;
    for(int n = 3; n <= MAX_NUM; n += 2) {
        if(!GET(n >> 1)) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 1, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            SET(temp >> 1);
            if(n % primes[i] == 0)
                break;
        }
    }
}

long solve(long n) {
    long ans = 0;
    int limit = sqrt(n);
    for(int i = 0; i < size && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0) {
            int temp = 1;
            do {
                n /= primes[i];
                temp *= primes[i];
            } while(n % primes[i] == 0);
            ans += temp;
            limit = sqrt(n);
        }
    }
    if(n > 1)
        ans += n;
    return ans;
}

int main() {
    eulerSieve();
    int cases = 0;
    long N;
    while(scanf("%ld", &N) && N != 0) {
        if(N == 1)
            printf("Case %d: 2\n", ++cases);
        else {
            long ans = solve(N);
            printf("Case %d: %ld\n", ++cases, ans == N ? N + 1 : ans);
        }
    }
    free(primes);
	return 0;
}
