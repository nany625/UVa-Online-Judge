#include <stdio.h>
#include <stdlib.h>
#define MAXV 11
#define INF 1e9

typedef struct {
    int x, y;
} Coordinate;

int dp[1 << MAXV][MAXV], dist[MAXV][MAXV];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int scenarios;
    scanf("%d", &scenarios);
    while(scenarios--) {
        scanf("%*d %*d");
        Coordinate start;
        scanf("%d %d", &start.x, &start.y);
        int n;
        scanf("%d", &n);
        Coordinate beepers[++n];
        beepers[0] = start;
        for(int i = 1; i < n; ++i)
            scanf("%d %d", &beepers[i].x, &beepers[i].y);
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j)
                dist[i][j] = dist[j][i] = abs(beepers[i].x - beepers[j].x) + abs(beepers[i].y - beepers[j].y);
        }
        int FULL = 1 << n;
        for(int i = 0; i < FULL; ++i) {
            for(int j = 0; j < n; ++j)
                dp[i][j] = INF;
        }
        dp[1][0] = 0;
        for(int mask = 1; mask < FULL; ++mask) {
            for(int u = 0; u < n; ++u) {
                if(mask & (1 << u)) {
                    for(int v = 0; v < n; ++v) {
                        if(!(mask & (1 << v))) {
                            int next = mask | (1 << v);
                            dp[next][v] = min(dp[next][v], dp[mask][u] + dist[u][v]);
                        }
                    }
                }
            }
        }
        int ans = INF;
        for(int i = 1; i < n; ++i)
            ans = min(ans, dp[FULL - 1][i] + dist[i][0]);
        printf("The shortest path has length %d\n", ans);
    }
    return 0;
}
