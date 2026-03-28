#include <stdio.h>
#include <math.h>
#define MAXV 8
#define INF 1e9

typedef struct {
    int x, y;
} Coordinate;

double dp[1 << MAXV][MAXV], dist[MAXV][MAXV];
int parent[1 << MAXV][MAXV], path[MAXV];

void findPath(int mask, int end) {
    int idx = 0;
    while(end != -1) {
        path[idx++] = end;
        int temp = parent[mask][end];
        mask ^= (1 << end);
        end = temp;
    }
}

int main() {
    int networks = 0, computers;
    while(scanf("%d", &computers) && computers != 0) {
        Coordinate node[computers];
        for(int i = 0; i < computers; ++i)
            scanf("%d %d", &node[i].x, &node[i].y);
        for(int i = 0; i < computers - 1; ++i) {
            for(int j = i + 1; j < computers; ++j)
                dist[i][j] = dist[j][i] = sqrt((node[i].x - node[j].x) * (node[i].x - node[j].x) + (node[i].y - node[j].y) * (node[i].y - node[j].y));
        }
        int FULL = 1 << computers;
        double cableLen = INF;
        for(int i = 0; i < computers; ++i) {
            for(int j = 0; j < FULL; ++j) {
                for(int k = 0; k < computers; ++k) {
                    dp[j][k] = INF;
                    parent[j][k] = -1;
                }
            }
            dp[1 << i][i] = 0;
            for(int mask = 1; mask < FULL; ++mask) {
                for(int u = 0; u < computers; ++u) {
                    if(mask & (1 << u)) {
                        for(int v = 0; v < computers; ++v) {
                            if(!(mask & (1 << v))) {
                                int next = mask | (1 << v);
                                if (dp[next][v] > dp[mask][u] + dist[u][v]) {
                                    dp[next][v] = dp[mask][u] + dist[u][v];
                                    parent[next][v] = u;
                                }
                            }
                        }
                    }
                }
            }
            int end = 0;
            for(int j = 1; j < computers; ++j) {
                if(dp[FULL - 1][end] > dp[FULL - 1][j])
                    end = j;
            }
            if(cableLen > dp[FULL - 1][end]) {
                cableLen = dp[FULL - 1][end];
                findPath(FULL - 1, end);
            }
        }
        printf("**********************************************************\nNetwork #%d\n", ++networks);
        for(int i = computers - 1; i > 0; --i)
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", node[path[i]].x, node[path[i]].y, node[path[i - 1]].x, node[path[i - 1]].y, 16 + dist[path[i]][path[i - 1]]);
        printf("Number of feet of cable required is %.2f.\n", cableLen + 16 * (computers - 1));
    }
    return 0;
}
