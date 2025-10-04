#include <stdio.h>
#include <stdlib.h>
#define INF 1e9

int dist[100][100];

void floydWarshall(int V) {
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j)
                dist[i][j] = dist[i][j] < dist[i][k] + dist[k][j] ? dist[i][j] : dist[i][k] + dist[k][j];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char w[4];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            dist[i][j] = i == j ? 0 : INF;
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            scanf("%s", w);
            if(w[0] != 'x')
                dist[i][j] = dist[j][i] = atoi(w);
        }
    }
    floydWarshall(n);
    int ans = dist[0][1];
    for(int i = 2; i < n; ++i)
        ans = ans > dist[0][i] ? ans : dist[0][i];
    printf("%d\n", ans);
    return 0;
}
