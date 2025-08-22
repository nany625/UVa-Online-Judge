#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INF 1e9
#define MAXV 100

int dist[MAXV][MAXV], next[MAXV][MAXV], tax[MAXV];

void floydWarshall(int V) {
    for(int k = 1; k <= V; ++k) {
        for(int i = 1; i <= V; ++i) {
            for(int j = 1; j <= V; ++j) {
                if(dist[i][j] > dist[i][k] + dist[k][j] + tax[k]) {
                    dist[i][j] = dist[i][k] + dist[k][j] + tax[k];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void printPath(int source, int destination) {
    while(source != destination) {
        source = next[source][destination];
        printf("-->%d", source);
    }
}

int main() {
    int M;
    scanf("%d ", &M);
    char *buffer = NULL;
    size_t bufsize = 0;
    bool blankLine = false;
    while(M--) {
        int N = 0;
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        while(token) {
            dist[1][++N] = atoi(token);
            if(dist[1][N] == -1)
                dist[1][N] = INF;
            next[1][N] = N;
            token = strtok(NULL, " ");
        }
        for(int i = 2; i <= N; ++i) {
            getline(&buffer, &bufsize, stdin);
            token = strtok(buffer, " ");
            for(int j = 1; j <= N; ++j) {
                dist[i][j] = atoi(token);
                if(dist[i][j] == -1)
                    dist[i][j] = INF;
                next[i][j] = j;
                token = strtok(NULL, " ");
            }
        }
        for(int i = 1; i <= N; ++i)
            scanf("%d ", &tax[i]);
        floydWarshall(N);
        int source, destination;
        while(getline(&buffer, &bufsize, stdin) != -1 && sscanf(buffer, "%d %d", &source, &destination) == 2) {
            if(blankLine)
                putchar('\n');
            printf("From %d to %d :\nPath: %d", source, destination, source);
            printPath(source, destination);
            printf("\nTotal cost : %d\n", dist[source][destination]);
            blankLine = true;
        }
    }
    free(buffer);
	return 0;
}
