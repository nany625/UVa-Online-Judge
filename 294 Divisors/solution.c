#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 31607

bool isComposite[MAX_NUM + 1];
short *primes;
int size = 1;

int factorCount(int n) {
    int result = 1, i = 0;
	while(i < size && n > 1) {
	    int currPow = 0;
	    while(n % primes[i] == 0) {
	        ++currPow;
	        n /= primes[i];
	    }
	    result *= currPow + 1;
	    ++i;
	}
	if(n > 1)
	    result <<= 1;
	return result;
}

int main() {
    primes = (short*)malloc(sizeof(short));
    primes[0] = 2;
    for(short i = 3; i <= MAX_NUM; i += 2) {
        if(!isComposite[i]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = i;
            if(i <= 177) {
                for(int j = i * i; j <= MAX_NUM; j += i << 1)
                    isComposite[j] = true;
            }
        }
    }
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
