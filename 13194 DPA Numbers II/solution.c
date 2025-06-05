#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 1000000

bool isComposite[(MAX_NUM >> 1) + 1];
int *primes, size = 1;

void eulerSieve() {
    primes = (int*)malloc(sizeof(int));
    primes[0] = 2;
    for(int n = 3; n <= MAX_NUM; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 1, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

long sumOfDivisors(long n) {
    long sum = 1, limit = sqrt(n);
    for(int i = 0; i < size && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0) {
            long tempSum = 1, term = 1;
            do {
                tempSum += term *= primes[i];
                n /= primes[i];
            } while(n % primes[i] == 0);
            sum *= tempSum;
            limit = sqrt(n);
        }
    }
    if(n > 1)
        sum *= (1 + n);
    return sum;
}

int main() {
    eulerSieve();
    int t;
	scanf("%d", &t);
	while(t--) {
	    long n;
	    scanf("%ld", &n);
	    if(n % 6 == 0 && n > 6)
	        puts("abundant");
	    else {
	        long sum = sumOfDivisors(n) - n;
    	    if(sum < n)
    	        puts("deficient");
    	    else if(sum == n)
    	        puts("perfect");
    		else
    			puts("abundant");
	    }
	}
	free(primes);
	return 0;
}
