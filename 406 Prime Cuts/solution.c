#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 1000

bool isComposite[MAX_NUM + 1];
short *primes, pos[MAX_NUM] = {1, 2};
int size = 2;

void printPrimes(int first, int last) {
	for(int i = first; i <= last; ++i)
		printf(" %hd", primes[i]);
}

int main() {
    primes = (short*)malloc(2 * sizeof(short));
    primes[0] = 1;
    primes[1] = 2;
	for(short i = 3; i <= MAX_NUM; ++i) {
	    pos[i - 1] = pos[i - 2];
	    if(i & 1 && !isComposite[i]) {
	        primes = (short*)realloc(primes, (size + 1) * sizeof(short));
	        ++pos[(primes[size++] = i) - 1];
	        if(i <= 31) {
	            for(int j = i * i; j <= MAX_NUM; j += i << 1)
	                isComposite[j] = true;
	        }
	    }
	}
	int N, C;
    while(scanf("%d %d", &N, &C) == 2) {
    	printf("%d %d:", N, C);
    	if(!(pos[N - 1] & 1) && C << 1 < pos[N - 1])
    		printPrimes((pos[N - 1] >> 1) - C, (pos[N - 1] >> 1) + C - 1);
    	else if(pos[N - 1] & 1 && (C << 1) - 1 < pos[N - 1])
    		printPrimes((pos[N - 1] + 1 >> 1) - C, (pos[N - 1] - 3 >> 1) + C);
    	else
    		printPrimes(0, pos[N - 1] - 1);
    	puts("\n");
    }
    free(primes);
	return 0;
}
