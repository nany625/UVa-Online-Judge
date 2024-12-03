#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 1000001

bool isHComposite[MAX_NUM + 1], isHSemiPrime[MAX_NUM + 1];
int ans[MAX_NUM + 1], *hPrimes, hPrimeSize;

int main() {
    for(int i = 5; i <= MAX_NUM; i += 4) {
        if(!isHComposite[i]) {
            hPrimes = (int*)realloc(hPrimes, (hPrimeSize + 1) * sizeof(int));
            hPrimes[hPrimeSize++] = i;
            for(int j = 0, temp; j < hPrimeSize && (temp = hPrimes[j] * i) <= MAX_NUM; ++j)
                isHSemiPrime[temp] = true;
            if(i <= 1000) {
                for(int j = i * i; j <= MAX_NUM; j += i << 2)
                    isHComposite[j] = true;
            }
        }
    }
    for(int i = 1; i <= MAX_NUM; ++i)
        ans[i] = ans[i - 1] + isHSemiPrime[i];
    int h;
    while(scanf("%d", &h) && h != 0)
        printf("%d %d\n", h, ans[h]);
    free(hPrimes);
    return 0;
}
