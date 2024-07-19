#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N;
        scanf("%d", &N);
        int prev;
        scanf("%d", &prev);
        --N;
        int curr, highJumps = 0, lowJumps = 0;
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
