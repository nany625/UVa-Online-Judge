#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 2703663

bool isComposite[MAX_NUM + 1];
int *primes, size, count[MAX_NUM + 1];

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

int binarySearch(int key) {
    int left = 2, right = MAX_NUM;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(count[mid] == key)
            return mid;
        if(count[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    eulerSieve();
    for(int i = 2; i <= MAX_NUM; ++i)
        count[i] += count[i - 1];
    int cases = 0, N;
    while(scanf("%d", &N) && N >= 0) {
        if(N == 0)
            printf("Case %d: 0!\n", ++cases);
        else {
            int pos = binarySearch(N);
            if(pos == -1)
                printf("Case %d: Not possible.\n", ++cases);
            else
                printf("Case %d: %d!\n", ++cases, pos);
        }
    }
    free(primes);
	return 0;
}
