#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 3507

short primes[MAX_SIZE] = {2};
int count = 1;

bool isPrime(short n) {
    short limit = sqrt(n);
    for(int i = 1; i < count && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

int binarySearch(short *array, int key) {
    int left = 0, right = MAX_SIZE - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(array[mid] == key)
            return mid;
        if(array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left - 1;
}

int main() {
	for(short i = 3; count < MAX_SIZE; i += 2) {
	    if(isPrime(i))
	        primes[count++] = i;
	}
	char line[25];
	while(fgets(line, sizeof(line), stdin) && strcmp(line, "0\n") != 0) {
	    int x = 1;
	    char *token = strtok(line, " ");
	    while(token) {
	        int p = atoi(token);
	        token = strtok(NULL, " ");
	        x *= pow(p, atoi(token));
	        token = strtok(NULL, " ");
	    }
	    --x;
	    int pos = binarySearch(primes, x);
	    bool space = false;
	    while(pos >= 0 && x > 1) {
	        if(x % primes[pos] == 0) {
	            if(space)
	                putchar(' ');
	            int e = 0;
	            do {
	                ++e;
	                x /= primes[pos];
	            } while(x % primes[pos] == 0);
	            printf("%hd %d", primes[pos], e);
	            space = true;
	        }
	        --pos;
	    }
	    puts("");
	}
	return 0;
}
