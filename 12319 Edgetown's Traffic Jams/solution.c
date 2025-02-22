#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INF 100
#define MAXV 100

int **dist, **newDist;

void floydWarshall(int **array, int V) {
    for(int k = 1; k <= V; ++k) {
        for(int i = 1; i <= V; ++i) {
            for(int j = 1; j <= V; ++j) {
                if(array[i][j] > array[i][k] + array[k][j])
                    array[i][j] = array[i][k] + array[k][j];
            }
        }
    }
}

bool accept(int **dist, int **newDist, int V, int A, int B) {
    for(int i = 1; i <= V; ++i) {
        for(int j = 1; j <= V; ++j) {
            if(newDist[i][j] > A * dist[i][j] + B)
                return false;
        }
    }
    return true;
}

int main() {
    int **dist = (int**)malloc((MAXV + 1) * sizeof(int*)), **newDist = (int**)malloc((MAXV + 1) * sizeof(int*));
    for(int i = 1; i <= MAXV; ++i) {
        dist[i] = (int*)malloc((MAXV + 1) * sizeof(int));
        newDist[i] = (int*)malloc((MAXV + 1) * sizeof(int));
    }
    int n;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%d", &n) && n != 0) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j)
                dist[i][j] = newDist[i][j] = i == j ? 0 : INF;
        }
        for(int u = 1; u <= n; ++u) {
            scanf("%*d");
            getline(&buffer, &bufsize, stdin);
            char *token = strtok(buffer, " ");
            while(token) {
                int v = atoi(token);
                dist[u][v] = 1;
                token = strtok(NULL, " ");
            }
        }
        floydWarshall(dist, n);
        for(int u = 1; u <= n; ++u) {
            scanf("%*d");
            getline(&buffer, &bufsize, stdin);
            char *token = strtok(buffer, " ");
            while(token) {
                int v = atoi(token);
                newDist[u][v] = 1;
                token = strtok(NULL, " ");
            }
        }
        floydWarshall(newDist, n);
        int A, B;
        scanf("%d %d", &A, &B);
        puts(accept(dist, newDist, n, A, B) ? "Yes" : "No");
    }
    free(buffer);
    for(int i = 1; i <= MAXV; ++i) {
        free(dist[i]);
        free(newDist[i]);
    }
    free(dist);
    free(newDist);
	return 0;
}
