#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 1000000

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
