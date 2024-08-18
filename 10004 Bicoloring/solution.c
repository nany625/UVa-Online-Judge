#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NUM 198

typedef struct {
    short numVertices, **edges, edgesCount[MAX_NUM + 1];
    char color[MAX_NUM + 1];
} Graph;

void dfs(Graph *graph, int startVertex, char color, bool *bicolorable) {
    graph->color[startVertex] = color;
    for(int i = 0; i < graph->edgesCount[startVertex]; ++i) {
        if(graph->color[graph->edges[startVertex][i]] == '\0')
            dfs(graph, graph->edges[startVertex][i], color == '0' ? '1' : '0', bicolorable);
        else if(graph->color[graph->edges[startVertex][i]] == color) {
            *bicolorable = false;
            return;
        }
    }
}

int main() {
    Graph graph;
    graph.edges = (short**)malloc((MAX_NUM + 1) * sizeof(short*));
    for(int i = 0; i <= MAX_NUM; ++i)
        graph.edges[i] = NULL;
    while(scanf("%hd", &graph.numVertices) && graph.numVertices != 0) {
        short l;
        scanf("%hd", &l);
        memset(graph.edgesCount, 0, graph.numVertices * sizeof(short));
        short startVertex;
        while(l--) {
            short a, b;
            scanf("%hd %hd", &a, &b);
            graph.edges[a] = (short*)realloc(graph.edges[a], (graph.edgesCount[a] + 1) * sizeof(short));
            graph.edges[a][graph.edgesCount[a]++] = b;
            graph.edges[b] = (short*)realloc(graph.edges[b], (graph.edgesCount[b] + 1) * sizeof(short));
            startVertex = graph.edges[b][graph.edgesCount[b]++] = a;
        }
        memset(graph.color, '\0', graph.numVertices * sizeof(char));
        bool bicolorable = true;
        dfs(&graph, startVertex, '0', &bicolorable);
        puts(bicolorable ? "BICOLORABLE." : "NOT BICOLORABLE.");
    }
    for(int i = 0; i <= MAX_NUM; ++i)
        free(graph.edges[i]);
    free(graph.edges);
	return 0;
}
