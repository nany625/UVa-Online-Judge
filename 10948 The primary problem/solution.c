#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
int *primes, size;

void eulerSieve() {
    for(int n = 3; n <= MAX_NUM; n += 2) {
        if(!GET(n >> 1)) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            SET(temp >> 1);
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
            if(!GET(N - 2 >> 1))
                printf("2+%d\n", N - 2);
            else
                puts("NO WAY!");
        } else {
            int i = 3, j = N - 3;
            while(i <= j) {
                if(!GET(i >> 1) && !GET(j >> 1))
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
