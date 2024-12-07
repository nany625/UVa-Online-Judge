#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 32763

bool isComposite[(MAX_NUM >> 1) + 1];
short *primes, pairs[(MAX_NUM >> 1) + 1] = {1};
int size;

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

int main() {
    eulerSieve();
    for(int i = 0; i < size; ++i) {
        for(int j = i, sum; j < size && (sum = primes[i] + primes[j]) <= 32766; ++j) {
            ++pairs[(sum >> 1) - 2];
        }
    }
	int n;
	while(scanf("%d", &n) && n != 0)
		printf("%d\n", pairs[(n >> 1) - 2]);
    free(primes);
	return 0;
}
