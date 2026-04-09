#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000001
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 7) + 1], isHSemiPrime[MAX_NUM + 1];
int ans[MAX_NUM + 1], *hPrimes, size;

void eulerSieve() {
    for(int n = 5; n <= MAX_NUM; n += 4) {
        if(!GET(n >> 2)) {
            hPrimes = (int*)realloc(hPrimes, (size + 1) * sizeof(int));
            hPrimes[size++] = n;
        }
        for(int i = 0, temp; (temp = hPrimes[i] * n) <= MAX_NUM; ++i) {
            SET(temp >> 2);
            if(n % hPrimes[i] == 0)
                break;
        }
    }
}

int main() {
    eulerSieve();
    for(int i = 0; i < size; ++i) {
        for(int j = 0, temp; j < size && (temp = hPrimes[i] * hPrimes[j]) <= MAX_NUM; ++j)
            isHSemiPrime[temp >> 5] |= 1u << (temp & 31);
    }
    for(int i = 1; i <= MAX_NUM; ++i)
        ans[i] = ans[i - 1] + (isHSemiPrime[i >> 5] & (1u << (i & 31)) ? 1 : 0);
    int h;
    while(scanf("%d", &h) && h != 0)
        printf("%d %d\n", h, ans[h]);
    free(hPrimes);
    return 0;
}
