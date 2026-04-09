#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 10000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
short *primes, count[MAX_NUM + 1];
int size = 1;

void eulerSieve() {
    primes = (short*)malloc(sizeof(short));
    primes[0] = 2;
    for(short n = 3; n <= MAX_NUM; n += 2) {
        if(!GET(n >> 1)) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = n;
        }
        for(int i = 1, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            SET(temp >> 1);
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
        printf("%hd\n", count[num]);
    free(primes);
	return 0;
}
