#include <stdio.h>
#include <stdlib.h>
#define INF 1e9

void floydWarshall(int **dist, int V) {
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j)
                dist[i][j] = dist[i][j] < dist[i][k] + dist[k][j] ? dist[i][j] : dist[i][k] + dist[k][j];
        }
    }
}

int main() {
    int cases = 0, N, M;
    char names[22][11];
    while(scanf("%d %d", &N, &M) && N != 0) {
        int **dist = (int**)malloc(N * sizeof(int*));
        for(int i = 0; i < N; ++i) {
            scanf("%s", names[i]);
            dist[i] = (int*)malloc(N * sizeof(int));
            for(int j = 0; j < N; ++j)
                dist[i][j] = i == j ? 0 : INF;
        }
        while(M--) {
            int i, j, k;
            scanf("%d %d %d", &i, &j, &k);
            dist[i - 1][j - 1] = dist[j - 1][i - 1] = k;
        }
        floydWarshall(dist, N);
        int minCost = INF, minIndex = -1;
        for(int i = 0; i < N; ++i) {
            int cost = 0;
            for(int j = 0; j < N; ++j)
                cost += dist[i][j];
            if(minCost > cost) {
                minCost = cost;
                minIndex = i;
            }
            free(dist[i]);
        }
        printf("Case #%d : %s\n", ++cases, names[minIndex]);
        free(dist);
    }
	return 0;
}
