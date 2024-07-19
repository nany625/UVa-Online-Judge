#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N;
        scanf("%d", &N);
        int a[N], highJumps = 0, lowJumps = 0;
        scanf("%d", &a[0]);
        for(int j = 1; j < N; ++j) {
            scanf("%d", &a[j]);
            if(a[j] > a[j - 1])
                ++highJumps;
            else if(a[j] < a[j - 1])
                ++lowJumps;
        }
        printf("Case %d: %d %d\n", i, highJumps, lowJumps);
    }
    return 0;
}
