#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
    int cases = 0, a, b;
    while(scanf("%d %d", &a, &b) && a != 0) {
        memset(graph.linksCount, 0, sizeof(graph.linksCount));
        memset(graph.visited, 0, sizeof(graph.visited));
        graph.links[a] = (short*)realloc(graph.links[a], (graph.linksCount[a] + 1) * sizeof(short));
        graph.links[a][graph.linksCount[a]++] = b;
        int *nodes = (int*)malloc(2 * sizeof(int)), nodesCount = 2;
        graph.visited[nodes[0] = a] = graph.visited[nodes[1] = b] = true;
        while(scanf("%d %d", &a, &b) && a != 0) {
            graph.links[a] = (short*)realloc(graph.links[a], (graph.linksCount[a] + 1) * sizeof(short));
            graph.links[a][graph.linksCount[a]++] = b;
            if(!graph.visited[a]) {
                nodes = (int*)realloc(nodes, (nodesCount + 1) * sizeof(int));
                graph.visited[nodes[nodesCount++] = a] = true;
            }
            if(!graph.visited[b]) {
                nodes = (int*)realloc(nodes, (nodesCount + 1) * sizeof(int));
                graph.visited[nodes[nodesCount++] = b] = true;
            }
        }
        int path[nodesCount][nodesCount - 1], sum = 0;
        for(int i = 0; i < nodesCount; ++i) {
            memset(graph.visited, 0, sizeof(graph.visited));
            graph.visited[path[0][0] = nodes[i]] = true;
            int length = 1, currSize = 1;
            while(currSize > 0) {
                int nextSize = 0;
                for(int j = 0; j < currSize; ++j) {
                    for(int k = 0; k < graph.linksCount[path[length - 1][j]]; ++k) {
                        if(!graph.visited[graph.links[path[length - 1][j]][k]])
                            graph.visited[path[length][nextSize++] = graph.links[path[length - 1][j]][k]] = true;
                    }
                }
                sum += length++ * (currSize = nextSize);
            }
        }
        printf("Case %d: average length between pages = %.3lf clicks\n", ++cases, (double)sum / nodesCount / (nodesCount - 1));
        free(nodes);
    }
    for(int i = 1; i <= MAX_NUM; ++i)
        free(graph.links[i]);
    free(graph.links);
	return 0;
}
