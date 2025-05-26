#include <stdio.h>
#define INF 100
#define MAXV 100

int dist[MAXV][MAXV];

void floydWarshall(int V) {
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j)
                dist[i][j] = dist[i][j] < dist[i][k] + dist[k][j] ? dist[i][j] : dist[i][k] + dist[k][j];
        }
    }
}

int main() {
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
	    int N, R;
	    scanf("%d %d", &N, &R);
	    for(int j = 0; j < N; ++j) {
	        for(int k = 0; k < N; ++k)
	            dist[j][k] = j == k ? 0 : INF;
	    }
	    while(R--) {
	        int u, v;
	        scanf("%d %d", &u, &v);
	        dist[u][v] = dist[v][u] = 1;
	    }
	    floydWarshall(N);
	    int s, d;
	    scanf("%d %d", &s, &d);
	    int ans = 0;
	    for(int j = 0; j < N; ++j)
	        ans = ans > dist[s][j] + dist[j][d] ? ans : dist[s][j] + dist[j][d];
	    printf("Case %d: %d\n", i, ans);
	}
	return 0;
}
