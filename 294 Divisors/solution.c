#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_PRIME_SIZE 3401

short primes[MAX_PRIME_SIZE] = {2};
int count = 1;

bool isPrime(short n) {
    short limit = sqrt(n);
    for(int i = 1; i < count && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

int factorCount(int n) {
    int result = 1, i = 0;
	while(i < MAX_PRIME_SIZE && n > 1) {
	    int currPow = 0;
	    while(n % primes[i] == 0) {
	        ++currPow;
	        n /= primes[i];
	    }
	    result *= currPow + 1;
	    ++i;
	}
	return result;
}

int main() {
    for(short i = 3; count < MAX_PRIME_SIZE; i += 2) {
        if(isPrime(i))
            primes[count++] = i;
    }
	int N;
	scanf("%d", &N);
	while(N--) {
		int L, U;
		scanf("%d %d", &L, &U);
		printf("Between %d and %d, ", L, U);
		int ans = L;
		count = factorCount(L);
		L += L % 2;
		while(L % 6 != 0 && L <= U) {
		    int temp = factorCount(L);
			if(count < temp) {
				count = temp;
				ans = L;
			}
			L += 2;
		}
		for(int i = L; i <= U; i += 6) {
		    int temp = factorCount(i);
			if(count < temp) {
				count = temp;
				ans = i;
			}
		}
		printf("%d has a maximum of %d divisors.\n", ans, count);
	}
	return 0;
}
