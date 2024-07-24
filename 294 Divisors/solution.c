// #解法一
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
    int result = 1, i = 0, temp = n;
	while(i < MAX_PRIME_SIZE && temp > 1) {
	    int currPow = 0;
	    while(temp % primes[i] == 0) {
	        ++currPow;
	        temp /= primes[i];
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
		for(int i = L; i <= U; i += 2) {
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

// #解法二
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 31607
#define MAX_PRIME_SIZE 3401

bool isComposite[MAX_NUM + 1] = {true, true};
short primes[MAX_PRIME_SIZE] = {};
int count = 0;

int factorCount(int n) {
    int result = 1, i = 0, temp = n;
	while(i < MAX_PRIME_SIZE && temp > 1) {
	    int currPow = 0;
	    while(temp % primes[i] == 0) {
	        ++currPow;
	        temp /= primes[i];
	    }
	    result *= currPow + 1;
	    ++i;
	}
	return result;
}

int main() {
    int limit = sqrt(MAX_NUM);
	for(int i = 2; i <= MAX_NUM; ++i) {
		if(!isComposite[i]) {
			primes[count++] = i;
			if(i <= limit) {
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
		L += L % 2;
		for(int i = L; i <= U; i += 2) {
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
