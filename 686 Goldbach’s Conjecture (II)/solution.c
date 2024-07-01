#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 3512

bool map[32768] = {false, false, true};
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
        if(isPrime(i)) {
            map[i] = true;
            primes[count++] = i;
        }
    }
	int n;
	while(scanf("%d", &n) && n != 0) {
		count = map[n - 2];
		int limit = n / 2;
		for(int i = 1; primes[i] <= limit; ++i) {
			if(map[n - primes[i]])
				++count;
		}
		printf("%d\n", count);
	}
	return 0;
}
