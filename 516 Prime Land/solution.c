#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define MAX_PRIME_SIZE 3507

typedef struct {
    int p, e;
} Factor;

short primes[MAX_PRIME_SIZE] = {2};
int count = 1;

bool isPrime(int n) {
    int limit = sqrt(n);
    for(int i = 1; i < count && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

int main() {
	for(int i = 3; count < MAX_PRIME_SIZE; i += 2) {
	    if(isPrime(i))
	        primes[count++] = i;
	}
	char *buffer = NULL;
	size_t bufsize = 0;
	while(getline(&buffer, &bufsize, stdin) != -1 && buffer[0] != '0') {
	    char *token = strtok(buffer, " ");
	    int x = 1;
	    while(token) {
	        int p = atoi(token);
	        token = strtok(NULL, " ");
	        x *= pow(p, atoi(token));
	        token = strtok(NULL, " ");
	    }
	    --x;
	    Factor *factors = NULL;
	    int size = 0;
	    for(int i = 0; x > 1; ++i) {
	        if(x % primes[i] == 0) {
	            factors = (Factor*)realloc(factors, (size + 1) * sizeof(Factor));
	            factors[size].p = primes[i];
	            factors[size].e = 0;
	            do {
	                ++factors[size].e;
	                x /= primes[i];
	            } while(x % primes[i] == 0);
	            ++size;
	        }
	    }
	    for(int i = size - 1; i >= 0; --i) {
	        printf("%d %d", factors[i].p, factors[i].e);
	        if(i > 0)
	            putchar(' ');
	    }
	    putchar('\n');
	    free(factors);
	}
	free(buffer);
	return 0;
}
