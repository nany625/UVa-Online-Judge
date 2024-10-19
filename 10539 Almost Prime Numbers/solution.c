#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 999999

bool isComposite[MAX_NUM + 1];
long *almostPrimes = NULL;
int size = 0;

int compare(const void *a, const void *b) {
    return *(long*)a > *(long*)b;
}

void appendAlmostPrimes(int i) {
    long p = (long)i * i;
    while(p < 1000000000000) {
	    almostPrimes = (long*)realloc(almostPrimes, (size + 1) * sizeof(long));
	    almostPrimes[size++] = p;
	    p *= i;
    }
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
    appendAlmostPrimes(2);
	for(int i = 3; i <= MAX_NUM; i += 2) {
	    if(!isComposite[i]) {
	        appendAlmostPrimes(i);
	        if(i < 1000) {
	            for(int j = i * i; j <= MAX_NUM; j += i)
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
