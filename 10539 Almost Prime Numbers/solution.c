#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 999999
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
long *almostPrimes;
int size;

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

void eratosthenesSieve() {
    appendAlmostPrimes(2);
	for(int n = 3; n <= MAX_NUM; n += 2) {
	    if(!GET(n >> 1)) {
	        appendAlmostPrimes(n);
	        if(n <= 999) {
	            for(int i = n * n; i <= MAX_NUM; i += n << 1)
	                SET(i >> 1);
	        }
	    }
	}
}

int binarySearch(long key) {
	int left = 0, right = size - 1;
	while(left <= right) {
	    int mid = left + (right - left >> 1);
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
    eratosthenesSieve();
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
