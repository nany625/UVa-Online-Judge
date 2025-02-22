#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXV 300
#define INF 300

int dist[MAXV][MAXV], next[MAXV][MAXV];

void floydWarshall(int n) {
    for(int k = 1; k <= V; ++k) {
        for(int i = 1; i <= V; ++i) {
            for(int j = 1; j <= V; ++j) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

int main() {
    int n;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%d", &n) == 1) {
        puts("-----");
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j)
                dist[i][j] = i == j ? 0 : INF;
        }
        for(int i = 0; i < n; ++i) {
            int id;
            scanf("%d-", &id);
            getline(&buffer, &bufsize, stdin);
            char *token = strtok(buffer, ",");
            while(token) {
                int visit = atoi(token);
                dist[id][visit] = 1;
                next[id][visit] = visit;
                token = strtok(NULL, ",");
            }
        }
        floydWarshall(n);
        int m;
        scanf("%d", &m);
        while(m--) {
            int start, end;
            scanf("%d %d", &start, &end);
            if(dist[start][end] == INF)
                puts("connection impossible");
            else {
                do {
                    printf("%d ", start);
                    start = next[start][end];
                } while(start != end);
                printf("%d\n", end);
            }
        }
    }
    free(buffer);
	return 0;
}
