#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 5003
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
short *primes;
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
    int M;
    scanf("%d", &M);
    while(M--) {
        short N;
        scanf("%hd", &N);
        N >>= 1;
        ++N;
        N += !(N & 1);
        while(GET(N >> 1))
            N += 2;
        printf("%hd\n", N);
    }
    free(primes);
	return 0;
}
