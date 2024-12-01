#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 524288
#define MAX_N 1048576

bool isComposite[MAX_NUM + 1];
bool isCompositePrime[MAX_N + 1];
int *primes, size = 1;

int main() {
    primes = (int*)malloc(sizeof(int));
    primes[0] = 2;
    isCompositePrime[4] = true;
    for(int i = 3; i <= MAX_NUM; i += 2) {
        if(!isComposite[i]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = i;
            int temp;
            for(int j = 0; j < size && (temp = primes[j] * i) <= MAX_N; ++j)
                isCompositePrime[temp] = true;
            if(i <= 724) {
                for(int j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
        }
    }
    int N;
    while(scanf("%d", &N) == 1) {
        int count = 0;
        while(N--) {
            int num;
            scanf("%d", &num);
            count += isCompositePrime[num];
        }
        printf("%d\n", count);
    }
    free(primes);
    return 0;
}
