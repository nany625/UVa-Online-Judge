#include <stdio.h>
#include <stdbool.h>
#define MAX_NUM 9127
#define MAX_PRIME_SIZE 1131

bool isComposite[MAX_NUM + 1];
short primes[MAX_PRIME_SIZE] = {2};
int count = 1;

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
	if(n > 1)
	    result *= 2;
	return result;
}

int main() {
    for(int i = 3; count < MAX_PRIME_SIZE; i += 2) {
		if(!isComposite[i]) {
			primes[count++] = i;
			if(i <= 95) {
				for(int j = i * i; j <= MAX_NUM; j += i)
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
		int ans = L;
		count = factorCount(L);
		L += (L + 1) % 2 + 1;
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
