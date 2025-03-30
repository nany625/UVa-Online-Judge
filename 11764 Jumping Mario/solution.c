#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N;
        scanf("%d", &N);
        int heights[N];
        for(int j = 0; j < N; ++j)
            scanf("%d", &heights[j]);
        int highJumps = 0, lowJumps = 0;
        for(int j = 1; j < N; ++j) {
            if(heights[j] > heights[j - 1])
                ++highJumps;
            else if(heights[j] < heights[j - 1])
                ++lowJumps;
        }
        printf("Case %d: %d %d\n", i, highJumps, lowJumps);
    }
    return 0;
}
