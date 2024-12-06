#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 1000001

bool isHComposite[MAX_NUM + 1], isHSemiPrime[MAX_NUM + 1];
int ans[MAX_NUM + 1], *hPrimes, size;

void eulerSieve() {
    for(int n = 5; n <= MAX_NUM; n += 4) {
        if(!isHComposite[n]) {
            hPrimes = (int*)realloc(hPrimes, (size + 1) * sizeof(int));
            hPrimes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = hPrimes[i] * n) <= MAX_NUM; ++i) {
            isHComposite[temp] = true;
            if(n % hPrimes[i] == 0)
                break;
        }
    }
}

int main() {
    eulerSieve();
    for(int i = 0; i < size; ++i) {
        for(int j = 0, temp; j < size && (temp = hPrimes[i] * hPrimes[j]) <= MAX_NUM; ++j)
            isHSemiPrime[temp] = true;
    }
    for(int i = 1; i <= MAX_NUM; ++i)
        ans[i] = ans[i - 1] + isHSemiPrime[i];
    int h;
    while(scanf("%d", &h) && h != 0)
        printf("%d %d\n", h, ans[h]);
    free(hPrimes);
    return 0;
}
