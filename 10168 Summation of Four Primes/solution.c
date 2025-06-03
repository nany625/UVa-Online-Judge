#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXN 9999993

bool isComposite[(MAXN >> 1) + 1];
int *primes, size, ans[3];

void eulerSieve() {
    for(int n = 3; n <= MAXN; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAXN; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int compare(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int main() {
    eulerSieve();
    int N;
    while(scanf("%d", &N) == 1) {
        if(N < 8)
            puts("Impossible.");
        else if(N & 1) {
            if(!isComposite[N - 6 >> 1])
                printf("2 2 2 %d\n", N - 6);
            else {
                N -= 5;
                int i = 0;
                while(isComposite[primes[i] >> 1] || isComposite[N - primes[i] >> 1])
                    ++i;
                ans[0] = 3;
                ans[1] = primes[i];
                ans[2] = N - primes[i];
                qsort(ans, 3, sizeof(int), compare);
                printf("2 %d %d %d\n", ans[0], ans[1], ans[2]);
            }
        } else {
            if(N == 8)
                puts("2 2 2 2");
            else {
                N -= 4;
                int i = 0;
                while(isComposite[primes[i] >> 1] || isComposite[N - primes[i] >> 1])
                    ++i;
                printf("2 2 %d %d\n", primes[i], N - primes[i]);
            }
        }
    }
    free(primes);
	return 0;
}
