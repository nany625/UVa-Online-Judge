#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 5000000

bool isComposite[MAX_NUM + 1];
int *primes, sum[MAX_NUM + 1], count[MAX_NUM + 1], size;

void eulerSieve() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(!isComposite[n]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = sum[n] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp] = true;
            if(n % primes[i] == 0) {
                sum[temp] = sum[n];
                break;
            } else
                sum[temp] = sum[n] + primes[i];
        }
        count[n] = count[n - 1] + !isComposite[sum[n]];
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
