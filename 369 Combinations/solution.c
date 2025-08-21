#include <stdio.h>

unsigned long ans[101][101];

int main() {
    for(int i = 1; i <= 100; ++i)
        ans[i][1] = i;
    for(int i = 2; i <= 100; ++i) {
        for(int j = i; j <= 100; ++j)
            ans[j][i] = ans[j - 1][i - 1] + ans[j - 1][i];
    }
    int N, M;
    while(scanf("%d %d", &N, &M) && N != 0)
        printf("%d things taken %d at a time is %lu exactly.\n", N, M, ans[N][M]);
    return 0;
}
