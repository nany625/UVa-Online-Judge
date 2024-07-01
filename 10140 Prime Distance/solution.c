#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 4792

int primes[MAX_SIZE] = {2}, count = 1;

bool isPrime(int n) {
    int limit = sqrt(n);
	for(int i = 0; i < count && primes[i] <= limit; ++i) {
		if(n % primes[i] == 0)
			return false;
	}
	return true;
}

bool binarySearch(int *array, int key) {
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

int main() {
    for(int i = 3; count < MAX_SIZE; i += 2) {
        if(isPrime(i))
            primes[count++] = i;
    }
    int L, U;
    while(scanf("%d %d", &L, &U) == 2) {
    	int *primeList = NULL, C1, C2, D1, D2, size = 0;
    	if(L == 1) {
    	    primeList = (int*)realloc(primeList, (size + 2) * sizeof(int));
    	    primeList[size++] = C1 = D1 = 1;
    	    primeList[size++] = C2 = D2 = 2;
    	    L = 3;
    	} else if(L == 2) {
    	    primeList = (int*)realloc(primeList, (size + 1) * sizeof(int));
    	    primeList[size++] = 2;
    	    L = 3;
    	} else
    	    L += (L + 1) % 2;
        for(int i = L; i <= U; i += 2) {
            if(i <= primes[MAX_SIZE - 1]) {
                if(binarySearch(primes, i)) {
                    primeList = (int*)realloc(primeList, (size + 1) * sizeof(int));
                    primeList[size++] = i;
                }
            } else {
                if(isPrime(i)) {
                    primeList = (int*)realloc(primeList, (size + 1) * sizeof(int));
                    primeList[size++] = i;
                }
            }
            if(size == 2) {
                C1 = D1 = primeList[0];
                C2 = D2 = primeList[1];
            } else if(size > 2) {
                if(C2 - C1 > primeList[size - 1] - primeList[size - 2]) {
                    C1 = primeList[size - 2];
                    C2 = primeList[size - 1];
                }
                if(D2 - D1 < primeList[size - 1] - primeList[size - 2]) {
                    D1 = primeList[size - 2];
                    D2 = primeList[size - 1];
                }
            }
        }
        if(size < 2)
        	puts("There are no adjacent primes.");
        else	
        	printf("%d,%d are closest, %d,%d are most distant.\n", C1, C2, D1, D2);
        free(primeList);
    }
    return 0;
}
