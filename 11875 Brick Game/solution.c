#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N;
        scanf("%d", &N);
        int ages[N];
        for(int j = 0; j < N; ++j)
            scanf("%d", &ages[j]);
        printf("Case %d: %d\n", i, ages[N >> 1]);
    }
    return 0;
}
