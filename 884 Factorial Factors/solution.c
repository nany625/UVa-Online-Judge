#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 5) + 1];
int *primes, size, ans[MAX_NUM + 1];

void eulerSieve() {
	for(int n = 2; n <= MAX_NUM; ++n) {
		if(!GET(n)) {
			primes = (int*)realloc(primes, (size + 1) * sizeof(int));
			primes[size++] = n;
			ans[n] = 1;
		}
		for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
			SET(temp);
			ans[temp] = ans[primes[i]] + ans[n];
			if(n % primes[i] == 0)
				break;
		}
	}
}

int main() {
    eulerSieve();
    for(int i = 2; i <= MAX_NUM; ++i)
        ans[i] += ans[i - 1];
    int n;
    while(scanf("%d", &n) == 1)
        printf("%d\n", ans[n]);
    free(primes);
	return 0;
}
