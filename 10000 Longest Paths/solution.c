#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 100

typedef struct {
    short **links, linksCount[MAX_NUM + 1];
    bool visited[MAX_NUM + 1];
} Graph;

int main() {
    Graph graph;
    graph.links = (short**)malloc((MAX_NUM + 1) * sizeof(short*));
    for(int i = 1; i <= MAX_NUM; ++i)
        graph.links[i] = NULL;
    int cases = 0, n;
    while(scanf("%d", &n) && n != 0) {
        int s;
        scanf("%d", &s);
        memset(graph.linksCount, 0, sizeof(graph.linksCount));
        int p, q;
        while(scanf("%d %d", &p, &q) && p != 0) {
            graph.links[p] = (short*)realloc(graph.links[p], (graph.linksCount[p] + 1) * sizeof(short));
            graph.links[p][graph.linksCount[p]++] = q;
        }
        int path[n][n - 1];
        path[0][0] = s;
        int length = 1, currSize = 1;
        while(true) {
            memset(graph.visited, 0, sizeof(graph.visited));
            int nextSize = 0;
            for(int i = 0; i < currSize; ++i) {
                for(int j = 0; j < graph.linksCount[path[length - 1][i]]; ++j) {
                    if(!graph.visited[graph.links[path[length - 1][i]][j]])
                        graph.visited[path[length][nextSize++] = graph.links[path[length - 1][i]][j]] = true;
                }
            }
            if(nextSize == 0)
                break;
            ++length;
            currSize = nextSize;
        }
        int finish = path[length - 1][0];
        for(int i = 1; i < currSize; ++i)
            finish = finish < path[length - 1][i] ? finish : path[length - 1][i];
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++cases, s, length - 1, finish);
    }
    for(int i = 1; i <= MAX_NUM; ++i)
        free(graph.links[i]);
    free(graph.links);
	return 0;
}
