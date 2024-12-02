#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 1000000

bool isComposite[MAX_NUM + 1];
int *primes, size = 1;

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
    primes = (int*)malloc(sizeof(int));
    primes[0] = 2;
    for(int i = 3; i <= MAX_NUM; i += 2) {
        if(!isComposite[i]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = i;
            if(i <= 1000) {
                for(int j = i * i; j <= MAX_NUM; j += i << 1)
                    isComposite[j] = true;
            }
        }
    }
    int t;
	scanf("%d", &t);
	while(t--) {
	    long n;
	    scanf("%ld", &n);
	    if(n > 6 && n % 6 == 0)
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
