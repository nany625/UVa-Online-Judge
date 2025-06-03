#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 31622

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

int sumOfDigits(int n) {
    int result = 0;
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int sumOfFactorDigits(int n) {
    int result = 0, limit = sqrt(n), temp = n;
    for(int i = 0; i < size && primes[i] <= limit; ++i) {
	    if(n % primes[i] == 0) {
	        int tempSum = sumOfDigits(primes[i]);
	        do {
	            result += tempSum;
	            n /= primes[i];
	        } while(n % primes[i] == 0);
	        limit = sqrt(n);
	    }
	}
	if(temp == n)
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
	        if(n & 1 && n <= MAX_NUM && !isComposite[n >> 1])
	            continue;
	        found = sumOfFactorDigits(n) == sumOfDigits(n);
	    } while(!found);
	    printf("%d\n", n);
	}
	free(primes);
    return 0;
}
