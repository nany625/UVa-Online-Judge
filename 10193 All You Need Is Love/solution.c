#include <stdio.h>
#include <stdlib.h>

int GCD(long i, long j) {
    return j == 0 ? i : GCD(j, i % j);
}

int main() {
    int N;
    scanf("%d", &N);
    char S1[17], S2[17];
    for(int i = 1; i <= N; ++i) {
        scanf("%s %s", S1, S2);
        printf("Pair #%d: %s!\n", i, GCD(strtol(S1, NULL, 2), strtol(S2, NULL, 2)) > 1 ? "All you need is love" : "Love is not all you need");
    }
    return 0;
}
