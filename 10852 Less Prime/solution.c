#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 5003

bool isComposite[(MAX_NUM >> 1) + 1];
short *primes;
int size;

void eulerSieve() {
	for(short n = 3; n <= MAX_NUM; n += 2) {
		if(!isComposite[n >> 1]) {
		    primes = (short*)realloc(primes, (size + 1) * sizeof(short));
			primes[size++] = n;
		}
		for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
			isComposite[temp >> 1] = true;
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
        while(isComposite[N >> 1])
            N += 2;
        printf("%hd\n", N);
    }
    free(primes);
	return 0;
}
