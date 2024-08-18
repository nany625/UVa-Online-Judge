#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NUM 10000

typedef struct {
    short numVertices, **knockList, knockCount[MAX_NUM + 1];
    bool visited[MAX_NUM + 1];
} Graph;

void dfs(Graph *graph, int startVertex, int *count) {
    graph->visited[startVertex] = true;
    ++(*count);
    for(short i = 0; i < graph->knockCount[startVertex]; ++i) {
        if(!graph->visited[graph->knockList[startVertex][i]])
            dfs(graph, graph->knockList[startVertex][i], count);
    }
}

int main() {
    Graph graph;
    graph.knockList = (short**)malloc((MAX_NUM + 1) * sizeof(short*));
    for(short i = 1; i <= MAX_NUM; ++i)
        graph.knockList[i] = NULL;
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        short m, l;
        scanf("%hd %hd %hd", &graph.numVertices, &m, &l);
        memset(graph.knockCount, 0, (graph.numVertices + 1) * sizeof(short));
        while(m--) {
            short x, y;
            scanf("%hd %hd", &x, &y);
            graph.knockList[x] = (short*)realloc(graph.knockList[x], (graph.knockCount[x] + 1) * sizeof(short));
            graph.knockList[x][graph.knockCount[x]++] = y;
        }
        memset(graph.visited, 0, (graph.numVertices + 1) * sizeof(bool));
        int count = 0;
        while(l--) {
            short z;
            scanf("%hd", &z);
            if(!graph.visited[z])
                dfs(&graph, z, &count);
        }
        printf("%d\n", count);
    }
    for(short i = 0; i <= graph.numVertices; ++i)
        free(graph.knockList[i]);
    free(graph.knockList);
	return 0;
}
