#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 3512

short primes[MAX_SIZE] = {2}, pairs[16382] = {1};
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
    for(int i = 1; i < MAX_SIZE; ++i) {
        for(int j = i; j < MAX_SIZE; ++j) {
            int sum = primes[i] + primes[j];
            if(sum < 32768)
                ++pairs[(sum >> 1) - 2];
        }
    }
	int n;
	while(scanf("%d", &n) && n != 0)
		printf("%d\n", pairs[(n >> 1) - 2]);
	return 0;
}
