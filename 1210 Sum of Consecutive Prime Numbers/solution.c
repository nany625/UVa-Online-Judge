#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 10000

bool isComposite[MAX_NUM + 1];
short *primes = NULL, primesSumCount[MAX_NUM + 1];
int size = 1;

int main() {
    primes = (short*)malloc(sizeof(short));
    primes[0] = 2;
    for(short i = 3; i <= MAX_NUM; i += 2) {
        if(!isComposite[i]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = i;
            if(i <= 100) {
                for(int j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
        }
    }
    for(int i = 0; i < size; ++i) {
        int sum = 0;
        for(int j = i; j < size && (sum += primes[j]) <= MAX_NUM; ++j)
            ++primesSumCount[sum];
    }
    int num;
    while(scanf("%d", &num) && num != 0)
        printf("%d\n", primesSumCount[num]);
    free(primes);
	return 0;
}
