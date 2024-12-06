#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 31622

bool isComposite[MAX_NUM + 1];
short *primes;
int size;

void eulerSieve() {
    for(short n = 2; n <= MAX_NUM; ++n) {
        if(!isComposite[n]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int sumOfDigits(int n) {
    int result = 0;
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int sumOfFactorDigits(int n) {
    int result = 0, limit = sqrt(n);
    bool isPrime = true;
    for(int i = 0; i < size && primes[i] <= limit; ++i) {
	    if(n % primes[i] == 0) {
            isPrime = false;
	        int tempSum = sumOfDigits(primes[i]);
	        do {
	            result += tempSum;
	            n /= primes[i];
	        } while(n % primes[i] == 0);
	        limit = sqrt(n);
	    }
	}
	if(isPrime)
	    return -1;
	if(n > 1)
	    result += sumOfDigits(n);
	return result;
}

int main() {
    eulerSieve();
	int cases;
	scanf("%d", &cases);
	while(cases--) {
	    int n;
	    scanf("%d", &n);
	    bool found = false;
	    do {
	        ++n;
	        if(n <= MAX_NUM && !isComposite[n])
	            continue;
	        found = sumOfFactorDigits(n) == sumOfDigits(n);
	    } while(!found);
	    printf("%d\n", n);
	}
	free(primes);
    return 0;
}
