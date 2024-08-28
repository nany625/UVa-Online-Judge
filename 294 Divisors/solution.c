#include <stdio.h>

int primes[] = {2, 3, 5, 7, 11, 13};

int factorCount(int n) {
    int result = 1, i = 0;
	while(i < 6 && n > 1) {
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
		while(L % 12 != 0 && L <= U) {
		    int temp = factorCount(L);
			if(count < temp) {
				count = temp;
				ans = L;
			}
			L += 6;
		}
		while(L <= U) {
		    int temp = factorCount(L);
			if(count < temp) {
				count = temp;
				ans = L;
			}
			L += 12;
		}
		printf("%d has a maximum of %d divisors.\n", ans, count);
	}
	return 0;
}
