#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_PRIMES_SIZE 1230

short primes[MAX_PRIMES_SIZE] = {2}, ppCount[10001] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    40, 40
};

int primeCount = 1;

bool isPrime(int n) {
    short limit = sqrt(n);
	for(int i = 1; i < primeCount && primes[i] <= limit; ++i) {
		if(n % primes[i] == 0)
			return false;
	}
	return true;
}

int main() {
	for(short i = 3; primeCount < MAX_PRIMES_SIZE; i += 2) {
	    if(isPrime(i))
	        primes[primeCount++] = i;
	}
	for(int i = 42; i <= 10000; ++i) {
	    ppCount[i] = ppCount[i - 1];
	    if(i % 41 == 0 || (i + 1) % 41 == 0)
	        continue;
	    ppCount[i] += isPrime(i * i + i + 41);
	}
    int a, b;
    while(scanf("%d %d", &a, &b) == 2)
        printf("%.2f\n", 100.0 * (ppCount[b] - ppCount[a] + (a == 0 || ppCount[a] > ppCount[a - 1])) / (b - a + 1) + 0.0000001);
    return 0;
}
