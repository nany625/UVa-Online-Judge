#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 5000000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 5) + 1];
int *primes, size, sum[MAX_NUM + 1], count[MAX_NUM + 1];

void eulerSieve() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(!GET(n)) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = sum[n] = n;
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            SET(temp);
            if(n % primes[i] == 0) {
                sum[temp] = sum[n];
                break;
            } else
                sum[temp] = sum[n] + primes[i];
        }
        count[n] = count[n - 1] + !GET(sum[n]);
    }
}

int main() {
    eulerSieve();
    int a;
    while(scanf("%d", &a) && a != 0) {
        int b;
        scanf("%d", &b);
        printf("%d\n", count[b] - count[a - 1]);
    }
    free(primes);
    return 0;
}
