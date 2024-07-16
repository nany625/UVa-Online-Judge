#include <stdio.h>

long F[45] = {1}, M[45] = {};

int main() {
    for(int i = 1; i < 45; ++i) {
        F[i] = M[i - 1] + 1;
        M[i] = F[i - 1] + M[i - 1];
    }
    int N;
    while(scanf("%d", &N) && N != -1)
        printf("%ld %ld\n", M[N], F[N] + M[N]);
    return 0;
}
