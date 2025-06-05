#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 1000

bool isComposite[MAX_NUM + 1];
short *primes, pos[MAX_NUM + 1] = {0, 1};
int size = 1;

void eulerSieve() {
    primes = (short*)malloc(sizeof(short));
    primes[0] = 1;
    for(short n = 2; n <= MAX_NUM; ++n) {
        pos[n] = pos[n - 1];
        if(!isComposite[n]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            ++pos[primes[size++] = n];
        }
        for(int i = 1, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

void printPrimes(int first, int last) {
	for(int i = first; i <= last; ++i)
		printf(" %hd", primes[i]);
}

int main() {
	eulerSieve();
	int N, C;
    while(scanf("%d %d", &N, &C) == 2) {
    	printf("%d %d:", N, C);
    	if(!(pos[N] & 1) && C << 1 < pos[N])
    		printPrimes((pos[N] >> 1) - C, (pos[N] >> 1) + C - 1);
    	else if(pos[N] & 1 && (C << 1) - 1 < pos[N])
    		printPrimes((pos[N] + 1 >> 1) - C, (pos[N] - 3 >> 1) + C);
    	else
    		printPrimes(0, pos[N] - 1);
    	puts("\n");
    }
    free(primes);
	return 0;
}
