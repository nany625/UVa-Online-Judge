#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 1000000

bool isComposite[(MAX_NUM >> 1) + 1];
int *primes, size = 1;

void eulerSieve() {
    primes = (int*)malloc(sizeof(int));
    primes[0] = 2;
    for(int n = 3; n <= MAX_NUM; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 1, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    eulerSieve();
    int N;
    while(scanf("%d", &N) && N != 0) {
        printf("%d:\n", N);
        if(N == 4)
            puts("2+2");
        else if(N & 1) {
            if(!isComposite[N - 2 >> 1])
                printf("2+%d\n", N - 2);
            else
                puts("NO WAY!");
        } else {
            int i = 3, j = N - 3;
            while(i <= j) {
                if(!isComposite[i >> 1] && !isComposite[j >> 1])
                    break;
                i += 2;
                j -= 2;
            }
            if(i <= j)
                printf("%d+%d\n", i, j);
            else
                puts("NO WAY!");
        }
    }
    free(primes);
    return 0;
}
