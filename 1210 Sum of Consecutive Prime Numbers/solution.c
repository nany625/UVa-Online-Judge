#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 10000

bool isComposite[MAX_NUM + 1];
short *primes, count[MAX_NUM + 1];
int size;

void eulerSieve() {
    for(short n = 2; n <= MAX_NUM; ++n) {
        if(!isComposite[n]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    eulerSieve();
    for(int i = 0; i < size; ++i) {
        for(int j = i, sum = 0; j < size && (sum += primes[j]) <= MAX_NUM; ++j)
            ++count[sum];
    }
    int num;
    while(scanf("%d", &num) && num != 0)
        printf("%d\n", count[num]);
    free(primes);
	return 0;
}
