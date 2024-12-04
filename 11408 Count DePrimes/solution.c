#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 5000000

bool isComposite[MAX_NUM + 1] = {true, true};
int *primes, sum[MAX_NUM + 1], count[MAX_NUM + 1], size;

int main() {
    for(int i = 2; i <= MAX_NUM; ++i) {
        if(!isComposite[i]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = i;
            sum[i] = i;
        }
        for(int j = 0, temp; j < size && (temp = primes[j] * i) <= MAX_NUM; ++j) {
            isComposite[temp] = true;
            if(i % primes[j] == 0) {
                sum[temp] = sum[i];
                break;
            } else
                sum[temp] = sum[i] + primes[j];
        }
        count[i] = count[i - 1] + !isComposite[sum[i]];
    }
    int a;
    while(scanf("%d", &a) && a != 0) {
        int b;
        scanf("%d", &b);
        printf("%d\n", count[b] - count[a - 1]);
    }
    free(primes);
    return 0;
}
