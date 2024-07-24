#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NUM 32693
#define MAX_PRIME_SIZE 3507

bool isComposite[MAX_NUM + 1] = {};
short primes[MAX_PRIME_SIZE] = {};
int count = 0;

int binarySearch(int key) {
    int left = 0, right = 3506;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(primes[mid] == key)
            return mid;
        if(primes[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    right = left - 1;
    left = 0;
    key /= 2;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(primes[mid] == key)
            return mid;
        if(primes[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left - 1;
}

int main() {
	for(int i = 2; count < MAX_PRIME_SIZE; ++i) {
		if(!isComposite[i]) {
			primes[count++] = i;
			if(i <= 180) {
				for(int j = i * i; j <= MAX_NUM; j += i)
					isComposite[j] = true;
			}
		}
	}
	char *buffer = NULL;
	size_t bufsize = 0;
	while(getline(&buffer, &bufsize, stdin) != -1 && buffer[0] != '0') {
	    char *token = strtok(buffer, " ");
	    int x = 1;
	    while(token) {
	        int p = atoi(token);
	        token = strtok(NULL, " ");
	        x *= pow(p, atoi(token));
	        token = strtok(NULL, " ");
	    }
	    int pos = --x >= MAX_NUM ? MAX_PRIME_SIZE - 1 : binarySearch(x);
	    bool space = false;
	    while(x > 1) {
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
	    putchar('\n');
	}
	free(buffer);
	return 0;
}
