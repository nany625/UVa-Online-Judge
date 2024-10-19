#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isComposite[1000000];
long *almostPrimes = NULL;
int size = 0;

int compare(const void *a, const void *b) {
    return *(long*)a > *(long*)b;
}

int binarySearch(long key) {
	int left = 0, right = size - 1;
	while(left <= right) {
	    int mid = left + ((right - left) >> 1);
	    if(almostPrimes[mid] == key)
            return mid;
        if(almostPrimes[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}
	
int main() {
	for(int i = 2; i < 1000000; ++i) {
	    if(!isComposite[i]) {
	        long p = (long)i * i;
	        while(p < 1000000000000) {
	            almostPrimes = (long*)realloc(almostPrimes, (size + 1) * sizeof(long));
	            almostPrimes[size++] = p;
	            p *= i;
	        }
	        if(i < 1000) {
	            for(int j = i * i; j < 1000000; j += i)
	                isComposite[j] = true;
	        }
	    }
	}
	qsort(almostPrimes, size, sizeof(long), compare);
	int N;
	scanf("%d", &N);
	while(N--) {
	    long low, high;
	    scanf("%ld %ld", &low, &high);
	    int posLow = binarySearch(low), posHigh = binarySearch(high);
	    printf("%d\n", posHigh - posLow + (posHigh < size && almostPrimes[posHigh] == high));
	}
	free(almostPrimes);
	return 0;
}
