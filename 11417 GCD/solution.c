#include <stdio.h>

int table[499] = {1};

int GCD(int i, int j) {
    return j == 0 ? i : GCD(j, i % j);
}

int main() {
    for(int i = 3; i < 501; ++i) {
        table[i - 2] = table[i - 3];
        for(int j = 1; j < i; ++j)
            table[i - 2] += GCD(i, j);
    }
    int N;
    while(scanf("%d", &N) && N != 0)
        printf("%d\n", table[N - 2]);
    return 0;
}
