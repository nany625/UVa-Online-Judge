#include <stdio.h>
#include <stdlib.h>

char primes[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
    73, 79, 83, 89, 97
};
short table[101][25];
int size[101];

void initTable(int n) {
    int temp = n;
    for(int i = 0; i < size[n - 1]; ++i)
        table[n][i] = table[n - 1][i];
    size[n] = size[n - 1];
    for(int i = 0; i < size[temp - 1] && n > 1; ++i) {
        while(n % primes[i] == 0) {
            ++table[temp][i];
            n /= primes[i];
        }
    }
    if(n > 1)
        table[temp][size[temp]++] = 1;
}

int main() {
    for(int n = 2; n <= 100; ++n)
        initTable(n);
    int N, D;
    while(scanf("%d %d", &N, &D) && (N != 0 || D != 0)) {
        D = abs(D);
        if(N <= 1)
            printf("%d\n", 1 / D);
        else {
            long ans = 1;
            for(int i = 0; i < size[N] && ans > 0; ++i) {
                int power = 0;
                while(D % primes[i] == 0) {
                    ++power;
                    D /= primes[i];
                }
                ans *= (table[N][i] + 1 - power);
            }
            if(ans <= 0 || D > 1)
                puts("0");
            else
                printf("%ld\n", ans);
        }
    }
    return 0;
}
