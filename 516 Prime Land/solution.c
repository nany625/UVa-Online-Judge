#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NUM 32693

typedef struct {
    short p;
    int e;
} Factor;

bool isComposite[(MAX_NUM >> 1) + 1];
short *primes;
int size = 1;

void eulerSieve() {
    primes = (short*)malloc(sizeof(short));
    primes[0] = 2;
    for(short n = 3; n <= MAX_NUM; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = n;
        }
        for(int i = 1, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    eulerSieve();
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
	    int factorCount = 0;
	    for(int i = 0; x > 1; ++i) {
	        if(x % primes[i] == 0) {
	            factors = (Factor*)realloc(factors, (factorCount + 1) * sizeof(Factor));
	            factors[factorCount] = (Factor){primes[i], 0};
	            do {
	                ++factors[factorCount].e;
	                x /= primes[i];
	            } while(x % primes[i] == 0);
	            ++factorCount;
	        }
	    }
	    for(int i = factorCount - 1; i > 0; --i)
	        printf("%hd %d ", factors[i].p, factors[i].e);
	    printf("%hd %d\n", factors[0].p, factors[0].e);
	    free(factors);
	}
	free(buffer);
	free(primes);
	return 0;
}
