#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000000

int count[MAXN + 1], *primes, size;

void eulerSieve() {
    for(int n = 2; n <= MAXN; ++n) {
        if(!count[n]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
            count[n] = 1;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAXN; ++i) {
            count[temp] = count[primes[i]] + count[n];
            if(n % primes[i] == 0)
                break;
        }
    }
}

int binarySearch(int key) {
    int left = 3, right = MAXN;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(count[mid] == key)
            return mid + 1;
        if(count[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    eulerSieve();
    for(int n = 3; n <= MAXN; ++n)
        count[n] += count[n - 1];
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", binarySearch(n));
    }
    free(primes);
    return 0;
}
