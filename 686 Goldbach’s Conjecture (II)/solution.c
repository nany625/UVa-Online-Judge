#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 32763
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
short *primes, pairs[(MAX_NUM >> 1) + 1] = {1};
int size;

void eulerSieve() {
    for(short n = 3; n <= MAX_NUM; n += 2) {
        if(!GET(n >> 1)) {
	        primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = n;
	    }
	    for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
	        SET(temp >> 1);
	        if(n % primes[i] == 0)
	            break;
	    }
    }
}

int main() {
    eulerSieve();
    for(int i = 0; i < size; ++i) {
        for(int j = i, sum; j < size && (sum = primes[i] + primes[j]) <= 32766; ++j) {
            ++pairs[(sum >> 1) - 2];
        }
    }
	int n;
	while(scanf("%d", &n) && n != 0)
		printf("%d\n", pairs[(n >> 1) - 2]);
    free(primes);
	return 0;
}
