#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N;
        scanf("%d", &N);
        int prev, curr, highJumps = 0, lowJumps = 0;
        scanf("%d", &prev);
        --N;
        while(N--) {
            scanf("%d", &curr);
            if(curr > prev)
                ++highJumps;
            else if(curr < prev)
                ++lowJumps;
            prev = curr;;
        }
        printf("Case %d: %d %d\n", i, highJumps, lowJumps);
    }
    return 0;
}
