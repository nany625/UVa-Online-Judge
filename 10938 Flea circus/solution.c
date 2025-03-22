#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXV 5000

int **conn, connCount[MAXV + 1], prev[MAXV + 1], path[MAXV], length;
bool visited[MAXV + 1];

void bfs(int a, int b) {
    int curr[MAXV], next[MAXV], currSize = 1;
    visited[curr[0] = a] = true;
    while(!visited[b]) {
        int nextSize = 0;
        for(int i = 0; i < currSize; ++i) {
            for(int j = 0; j < connCount[curr[i]]; ++j) {
                if(!visited[conn[curr[i]][j]]) {
                    next[nextSize++] = conn[curr[i]][j];
                    prev[conn[curr[i]][j]] = curr[i];
                    visited[conn[curr[i]][j]] = true;
                }
            }
        }
        for(int i = 0; i < nextSize; ++i)
            curr[i] = next[i];
        currSize = nextSize;
    }
}

void findPath(int a, int b) {
    length = 0;
    while(b != a) {
        path[length++] = b;
        b = prev[b];
    };
    path[length++] = a;
}

int main() {
    conn = (int**)malloc((MAXV + 1) * sizeof(int*));
    for(int i = 1; i <= MAXV; ++i)
        conn[i] = NULL;
    int n;
    while(scanf("%d", &n) && n != 0) {
        memset(connCount, 0, sizeof(connCount));
        for(int i = 1; i < n; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            conn[a] = (int*)realloc(conn[a], (connCount[a] + 1) * sizeof(int));
            conn[a][connCount[a]++] = b;
            conn[b] = (int*)realloc(conn[b], (connCount[b] + 1) * sizeof(int));
            conn[b][connCount[b]++] = a;
        }
        int l;
        scanf("%d", &l);
        while(l--) {
            memset(visited, 0, sizeof(visited));
            int a, b;
            scanf("%d %d", &a, &b);
            bfs(a, b);
            findPath(a, b);
            if(length & 1) 
                printf("The fleas meet at %d.\n", path[length >> 1]);
            else {
                if(path[(length >> 1) - 1] > path[length >> 1]) {
                    int temp = path[(length >> 1) - 1];
                    path[(length >> 1) - 1] = path[length >> 1];
                    path[length >> 1] = temp;
                }
                printf("The fleas jump forever between %d and %d.\n", path[(length >> 1) - 1], path[length >> 1]);
            }
        }
    }
    for(int i = 1; i <= MAXV; ++i)
        free(conn[i]);
    free(conn);
    return 0;
}
