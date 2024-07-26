#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_PRIME_SIZE 1229

short primes[MAX_PRIME_SIZE] = {2}, primesSumCount[10001] = {};
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
    for(short i = 3; count < MAX_PRIME_SIZE; i += 2) {
        if(isPrime(i))
            primes[count++] = i;
    }
    for(int i = 0; i < MAX_PRIME_SIZE; ++i) {
        int sum = 0;
        for(int j = i; j < MAX_PRIME_SIZE && (sum += primes[j]) <= 10000; ++j)
            ++primesSumCount[sum];
    }
    int num;
    while(scanf("%d", &num) && num != 0)
        printf("%d\n", primesSumCount[num]);
	return 0;
}
