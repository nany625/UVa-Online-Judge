#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 32000

bool isComposite[(MAX_NUM >> 1) + 1];
short *primes, **determinatePrimes;
int size, dtPrimeSize;

void eulerSieve() {
	for(short n = 3; n <= MAX_NUM; n += 2) {
	    if(!isComposite[n >> 1]) {
	        primes = (short*)realloc(primes, (size + 1) * sizeof(short));
	        primes[size++] = n;
	    }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int binarySearch(short key) {
	int left = 0, right = dtPrimeSize - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(determinatePrimes[mid][0] == key)
            return mid;
        if(determinatePrimes[mid][0] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}
	
int main() {
    eulerSieve();
    for(int i = 1; i < size - 1; ++i) {
        if(primes[i] << 1 == primes[i - 1] + primes[i + 1]) {
            determinatePrimes = (short**)realloc(determinatePrimes, (dtPrimeSize + 1) * sizeof(short*));
            determinatePrimes[dtPrimeSize] = (short*)malloc(3 * sizeof(short));
            determinatePrimes[dtPrimeSize][0] = primes[i - 1];
            do {
                ++i;
            } while(primes[i] << 1 == primes[i - 1] + primes[i + 1]);
            determinatePrimes[dtPrimeSize][1] = primes[i];
            determinatePrimes[dtPrimeSize++][2] = primes[i] - primes[i - 1];
        }
    }
    short x, y;
    while(scanf("%hd %hd", &x, &y) && (x != 0 || y != 0)) {
        if(x > y) {
		    short temp = x;
		   	x = y;
		   	y = temp;
		}
		int pos = binarySearch(x);
		while(pos < dtPrimeSize && determinatePrimes[pos][1] <= y) {
		    for(short i = determinatePrimes[pos][0]; i < determinatePrimes[pos][1]; i += determinatePrimes[pos][2])
		        printf("%hd ", i);
		    printf("%hd\n", determinatePrimes[pos++][1]);
		}
    }
    for(int i = 0; i < dtPrimeSize; ++i)
        free(determinatePrimes[i]);
    free(determinatePrimes);
    free(primes);
	return 0;
}
