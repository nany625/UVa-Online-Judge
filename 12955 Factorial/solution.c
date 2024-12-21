#include <stdio.h>

int factorial[] = {40320, 5040, 720, 120, 24, 6, 2, 1};

int main() {
    int N;
    while(scanf("%d", &N) == 1) {
        int k = 0;
        for(int i = 0; N > 0; ++i) {
            k += N / factorial[i];
            N %= factorial[i];
        }
        printf("%d\n", k);
    }
    return 0;
}
