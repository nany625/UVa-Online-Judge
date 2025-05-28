#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXP 1000

int **conn, connCount[MAXP], GiovanniNum[MAXP], bfs[MAXP], temp[MAXP];
bool visited[MAXP];

int main() {
    conn = (int**)malloc(MAXP * sizeof(int*));
    for(int i = 0; i < MAXP; ++i)
        conn[i] = NULL;
	int cases;
	scanf("%d", &cases);
	while(cases--) {
	    int P, D;
	    scanf("%d %d", &P, &D);
	    memset(connCount, 0, sizeof(connCount));
	    while(D--) {
            int p1, p2;
            scanf("%d %d", &p1, &p2);
            conn[p1] = (int*)realloc(conn[p1], (connCount[p1] + 1) * sizeof(int));
            conn[p1][connCount[p1]++] = p2;
            conn[p2] = (int*)realloc(conn[p2], (connCount[p2] + 1) * sizeof(int));
            conn[p2][connCount[p2]++] = p1;
	    }
	    memset(visited, 0, sizeof(visited));
	    visited[0] = true;
	    bfs[0] = 0;
	    int currSize = 1, n = 1;
        while(currSize > 0) {
            int nextSize = 0;
            for(int i = 0; i < currSize; ++i) {
                for(int j = 0; j < connCount[bfs[i]]; ++j) {
                    if(!visited[conn[bfs[i]][j]]) {
                        temp[nextSize++] = conn[bfs[i]][j];
                        GiovanniNum[conn[bfs[i]][j]] = n;
                        visited[conn[bfs[i]][j]] = true;
                    }
                }
            }
            for(int i = 0; i < nextSize; ++i)
                bfs[i] = temp[i];
            currSize = nextSize;
            ++n;
        }
	    for(int i = 1; i < P; ++i)
            printf("%d\n", GiovanniNum[i]);
        if(cases)
            putchar('\n');
	}
	for(int i = 0; i < MAXP; ++i)
        free(conn[i]);
    free(conn);
	return 0;
}
