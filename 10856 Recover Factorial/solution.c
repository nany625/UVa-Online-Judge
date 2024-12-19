#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 2703663

bool isComposite[MAX_NUM + 1];
int *primes, size, count[MAX_NUM + 1], ans[10000002];

void eulerSieve() {
	for(int n = 2; n <= MAX_NUM; ++n) {
		if(!isComposite[n]) {
			primes = (int*)realloc(primes, (size + 1) * sizeof(int));
			primes[size++] = n;
			count[n] = 1;
		}
		for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
			isComposite[temp] = true;
			count[temp] = count[primes[i]] + count[n];
			if(n % primes[i] == 0)
				break;
		}
	}
}

int main() {
    eulerSieve();
    for(int i = 2; i <= MAX_NUM; ++i) {
        count[i] += count[i - 1];
        if(ans[count[i]] == 0)
            ans[count[i]] = i;
    }
    int cases = 0, N;
    while(scanf("%d", &N) && N >= 0) {
        if(N == 0)
            printf("Case %d: 0!\n", ++cases);
        else if(ans[N] == 0)
            printf("Case %d: Not possible.\n", ++cases);
        else
            printf("Case %d: %d!\n", ++cases, ans[N]);
    }
    free(primes);
	return 0;
}
