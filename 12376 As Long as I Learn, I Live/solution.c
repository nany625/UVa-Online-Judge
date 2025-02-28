#include <stdio.h>
#include <string.h>
#define MAXV 100

int conn[MAXV][MAXV], connCount[MAXV], dist[MAXV][MAXV];

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        memset(connCount, 0, sizeof(connCount));
        int n, m;
        scanf("%d %d", &n, &m);
        int units[n];
        for(int j = 0; j < n; ++j)
            scanf("%d", &units[j]);
        while(m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            conn[u][connCount[u]++] = v;
            dist[u][v] = units[v];
        }
        int start = 0, gain = 0;
        while(connCount[start] > 0) {
            int maxIndex, maxDist = 0;
            for(int j = 0; j < connCount[start]; ++j) {
                if(maxDist < dist[start][conn[start][j]])
                    maxDist = dist[start][maxIndex = conn[start][j]];
            }
            gain += maxDist;
            start = maxIndex;
        }
        printf("Case %d: %d %d\n", i, gain, start);
    }
    return 0;
}
