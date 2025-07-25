#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 31622

bool isComposite[(MAX_NUM >> 1) + 1];
short *primes;
int size = 1;

void eulerSieve() {
    primes = (short*)malloc(sizeof(short));
    primes[0] = 2;
    for(short n = 3; n <= MAX_NUM; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = n;
        }
        for(int i = 1, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int factorCount(int n) {
    int result = 1, i = 0;
	while(i < size && n > 1) {
	    int term = 1;
	    while(n % primes[i] == 0) {
	        ++term;
	        n /= primes[i];
	    }
	    result *= term;
	    ++i;
	}
	if(n > 1)
	    result <<= 1;
	return result;
}

int main() {
    eulerSieve();
	int N;
	scanf("%d", &N);
	while(N--) {
		int L, U;
		scanf("%d %d", &L, &U);
		printf("Between %d and %d, ", L, U);
		int ans = L, count = factorCount(L);
		L += ((L + 1) & 1) + 1;
		while(L % 6 != 0 && L <= U) {
		    int temp = factorCount(L);
			if(count < temp) {
				count = temp;
				ans = L;
			}
			L += 2;
		}
		while(L <= U) {
		    int temp = factorCount(L);
			if(count < temp) {
				count = temp;
				ans = L;
			}
			L += 6;
		}
		printf("%d has a maximum of %d divisors.\n", ans, count);
	}
	free(primes);
	return 0;
}
