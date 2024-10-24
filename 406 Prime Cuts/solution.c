#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 169

short primes[MAX_SIZE] = {1, 2}, pos[1000] = {1, 2};
int count = 2;

bool isPrime(short n) {
    short limit = sqrt(n);
    for(int i = 2; i < count && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

void printPrimes(int first, int last) {
	for(int i = first; i <= last; ++i)
		printf(" %hd", primes[i]);
}

int main() {
	for(short i = 3; i <= 1000; ++i) {
	    pos[i - 1] = pos[i - 2];
	    if(i & 1 && count < MAX_SIZE) {
	        if(isPrime(i))
    			++pos[(primes[count++] = i) - 1];
	    }
	}
	int N, C;
    while(scanf("%d %d", &N, &C) == 2) {
    	printf("%d %d:", N, C);
    	if(!(pos[N - 1] & 1) && C << 1 < pos[N - 1])
    		printPrimes((pos[N - 1] >> 1) - C, (pos[N - 1] >> 1) + C - 1);
    	else if(pos[N - 1] & 1 && (C << 1) - 1 < pos[N - 1])
    		printPrimes((pos[N - 1] + 1 >> 1) - C, (pos[N - 1] - 3 >> 1) + C);
    	else
    		printPrimes(0, pos[N - 1] - 1);
    	puts("\n");
    }
	return 0;
}
