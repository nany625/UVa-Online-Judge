#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 9999999

bool isComposite[MAX_NUM + 1];
int *primes, size, ans[MAX_NUM + 1];

void eulerSieve() {
	for(int n = 2; n <= MAX_NUM; ++n) {
		if(!isComposite[n]) {
		    primes = (int*)realloc(primes, (size + 1) * sizeof(int));
			primes[size++] = n;
			ans[n] = 1;
		}
		for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
			isComposite[temp] = true;
			ans[temp] = ans[primes[i]] + ans[n];
			if(n % primes[i] == 0)
			    break;
		}
	}
}

int pfCount(long n) {
    int result = 0, limit = sqrt(n);
    for(int i = 0; i < size && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0) {
            do {
                ++result;
                n /= primes[i];
            } while(n % primes[i] == 0);
            limit = sqrt(n);
        }
    }
    return result + (n > 1);
}

int main() {
    eulerSieve();
    long n;
    while(scanf("%ld", &n) && n != 1)
        printf("%d\n",n <= MAX_NUM ? ans[n] : pfCount(n));
    free(primes);
	return 0;
}
