#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    short numVertices, **knockList, *knockCount;
    bool *visited;
} Graph;

Graph graph;

void dfs(Graph *graph, int vertex, int *count) {
    graph->visited[vertex] = true;
    ++(*count);
    for(short i = 0; i < graph->knockCount[vertex]; ++i) {
        if(!graph->visited[graph->knockList[vertex][i]])
            dfs(graph, graph->knockList[vertex][i], count);
    }
}

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        short m, l;
        scanf("%hd %hd %hd", &graph.numVertices, &m, &l);
        graph.knockList = (short**)malloc((graph.numVertices + 1) * sizeof(short*));
        for(short i = 1; i <= graph.numVertices; ++i)
            graph.knockList[i] = NULL;
        graph.knockCount = (short*)calloc(graph.numVertices + 1, sizeof(short));
        while(m--) {
            short x, y;
            scanf("%hd %hd", &x, &y);
            graph.knockList[x] = (short*)realloc(graph.knockList[x], (graph.knockCount[x] + 1) * sizeof(short));
            graph.knockList[x][graph.knockCount[x]++] = y;
        }
        graph.visited = (bool*)calloc(graph.numVertices + 1, sizeof(bool));
        int count = 0;
        while(l--) {
            short z;
            scanf("%hd", &z);
            if(!graph.visited[z])
                dfs(&graph, z, &count);
        }
        printf("%d\n", count);
        for(short i = 1; i <= graph.numVertices; ++i) {
            if(graph.knockCount[i] > 0)
                free(graph.knockList[i]);
        }
        free(graph.knockList);
        free(graph.knockCount);
        free(graph.visited);
    }
	return 0;
}
