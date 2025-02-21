#include <stdio.h>
#define INF 20

int dist[21][21];

void floydWarshall() {
    for(int k = 1; k <= 20; ++k) {
        for(int i = 1; i <= 20; ++i) {
            for(int j = 1; j <= 20; ++j)
                dist[i][j] = dist[i][j] < dist[i][k] + dist[k][j] ? dist[i][j] : dist[i][k] + dist[k][j];
        }
    }
}

int main() {
    int testSets = 0, X;
	while(scanf("%d", &X) == 1) {
	    printf("Test Set #%d\n", ++testSets);
	    for(int i = 1; i <= 20; ++i) {
	        for(int j = 1; j <= 20; ++j)
	            dist[i][j] = i == j ? 0 : INF;
	    }
	    while(X--) {
	        int v;
	        scanf("%d", &v);
	        dist[1][v] = dist[v][1] = 1;
	    }
	    for(int u = 2; u < 20; ++u) {
	        scanf("%d", &X);
	        while(X--) {
    	        int v;
    	        scanf("%d", &v);
    	        dist[u][v] = dist[v][u] = 1;
    	    }
	    }
	    floydWarshall();
	    int N;
	    scanf("%d", &N);
	    while(N--) {
	        int A, B;
	        scanf("%d %d", &A, &B);
	        printf("%2d to %2d: %d\n", A, B, dist[A][B]);
	    }
	    putchar('\n');
	}
	return 0;
}
