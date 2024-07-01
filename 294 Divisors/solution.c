#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 3401

short primes[MAX_SIZE] = {2};
int count = 1;

bool isPrime(short n) {
    short limit = sqrt(n);
    for(int i = 1; i < count && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

int main() {
    for(short i = 3; count < MAX_SIZE; i += 2) {
        if(isPrime(i))
            primes[count++] = i;
    }
	int N;
	scanf("%d", &N);
	while(N--) {
		int L, U;
		scanf("%d %d", &L, &U);
		int maxCount = 0, ans = L;
		for(int i = L; i <= U; ++i) {
			int factorCount = 1, j = 0, temp = i;
			while(j < MAX_SIZE && temp > 1) {
			    int currPow = 0;
			    while(temp % primes[j] == 0) {
			        ++currPow;
			        temp /= primes[j];
			    }
			    factorCount *= currPow + 1;
			    ++j;
			}
			if(maxCount < factorCount) {
				maxCount = factorCount;
				ans = i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, ans, maxCount);
	}
	return 0;
}
