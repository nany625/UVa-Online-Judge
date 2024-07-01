#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 78498

int primes[MAX_SIZE] = {2}, dpCount[999999] = {0, 1}, primesCount = 1;

bool isPrime(int n) {
    int limit = sqrt(n);
    for(int i = 0; i < primesCount && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

int sumOfDigits(int n) {
    int result = 0;
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main() {
	for(int i = 3; i < 1000000; ++i) {
	    dpCount[i - 1] = dpCount[i - 2];
	    if(i % 2 == 1 && primesCount < MAX_SIZE) {
	        if(isPrime(i)) {
	            primes[primesCount++] = i;
	            dpCount[i - 1] += isPrime(sumOfDigits(i));
	        }
	    }
	}
	int N;
	scanf("%d", &N);
	while(N--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		printf("%d\n", dpCount[t2 - 1] - dpCount[t1 - 1] + (dpCount[t1 - 1] > dpCount[t1 - 2]));
	}
	return 0;
}
