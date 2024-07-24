#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 31607
#define MAX_PRIME_SIZE 3401

bool isComposite[MAX_NUM + 1] = {};
short primes[MAX_PRIME_SIZE] = {};
int count = 0;

bool binarySearch(short *array, int key) {
    int left = 0, right = MAX_PRIME_SIZE - 1;
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

int sumOfFactorDigits(int n) {
    int result = 0, limit = sqrt(n);
    bool isPrime = true;
    for(int i = 0; i < MAX_PRIME_SIZE && primes[i] <= limit; ++i) {
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
	for(short i = 2; i <= MAX_NUM; ++i) {
	    if(!isComposite[i]) {
	        primes[count++] = i;
    	    if(i <= 177) {
    	        for(int j = i * i; j <= MAX_NUM; j += i)
    	            isComposite[j] = true;
    	    }
	    }
	}
	int cases;
	scanf("%d", &cases);
	while(cases--) {
	    int n;
	    scanf("%d", &n);
	    bool found = false;
	    do {
	        ++n;
	        if(n <= MAX_NUM) {
	            if(isComposite[n])
	                found = sumOfFactorDigits(n) == sumOfDigits(n);
	        } else
	            found = sumOfFactorDigits(n) == sumOfDigits(n);
	    } while(!found);
	    printf("%d\n", n);
	}
    return 0;
}
