#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 3401

short primes[MAX_SIZE] = {2};
int count = 1;

int isPrime(int n) {
    int limit = sqrt(n);
	for(int i = 0; i < count && primes[i] <= limit; ++i) {
		if(n % primes[i] == 0)
			return i;
	}
	return -1;
}

bool binarySearch(short *array, int key) {
    int left = 0, right = MAX_SIZE - 1;
	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(array[mid] == key)
			return true;
		if(array[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return false;
}

int sumOfDigits(int n) {
    int result = 0;
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int sumOfFactorDigits(int start, int n) {
    int result = 0;
    while(start < MAX_SIZE && n > 1) {
	    if(n % primes[start] == 0) {
	        result += sumOfDigits(primes[start]);
	        n /= primes[start];
	    } else
	        ++start;
	}
	if(n > 1)
	    result += sumOfDigits(n);
    return result;
}

int main() {
	for(short i = 3; count < MAX_SIZE; i += 2) {
	    if(isPrime(i) == -1)
	        primes[count++] = i;
	}
	int cases;
	scanf("%d", &cases);
	while(cases--) {
	    int n;
	    scanf("%d", &n);
	    bool found = false;
	    do {
	        ++n;
	        if(n <= primes[MAX_SIZE - 1]) {
	            if(!binarySearch(primes, n)) {
	                if(sumOfFactorDigits(0, n) == sumOfDigits(n))
	                    found = true;
	            }
	        } else {
	            int start = isPrime(n);
	            if(start != -1) {
	                if(sumOfFactorDigits(start, n) == sumOfDigits(n))
	                    found = true;
	            }
	        }
	    } while(!found);
	    printf("%d\n", n);
	}
    return 0;
}
