#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    short numVertices, **edges, *edgesCount;
    char *color;
    bool *visited;
} Graph;

void dfs(Graph *graph, int startVertex, char color, bool *bicolorable) {
    graph->visited[startVertex] = true;
    graph->color[startVertex] = color;
    for(int i = 0; i < graph->edgesCount[startVertex]; ++i) {
        if(!graph->visited[graph->edges[startVertex][i]])
            dfs(graph, graph->edges[startVertex][i], color == '0' ? '1' : '0', bicolorable);
        else if(graph->color[graph->edges[startVertex][i]] == color) {
            *bicolorable = false;
            return;
        }
    }
}

int main() {
    Graph graph;
    while(scanf("%hd", &graph.numVertices) && graph.numVertices != 0) {
        graph.edges = (short**)malloc(graph.numVertices * sizeof(short*));
        for(int i = 0; i < graph.numVertices; ++i)
            graph.edges[i] = NULL;
        graph.edgesCount = (short*)calloc(graph.numVertices, sizeof(short));
        short l;
        scanf("%hd", &l);
        short startVertex;
        while(l--) {
            short a, b;
            scanf("%hd %hd", &a, &b);
            graph.edges[a] = (short*)realloc(graph.edges[a], (graph.edgesCount[a] + 1) * sizeof(short));
            graph.edges[a][graph.edgesCount[a]++] = b;
            graph.edges[b] = (short*)realloc(graph.edges[b], (graph.edgesCount[b] + 1) * sizeof(short));
            startVertex = graph.edges[b][graph.edgesCount[b]++] = a;
        }
        graph.color = (char*)calloc(graph.numVertices, sizeof(char));
        graph.visited = (bool*)calloc(graph.numVertices, sizeof(bool));
        bool bicolorable = true;
        dfs(&graph, startVertex, '0', &bicolorable);
        puts(bicolorable ? "BICOLORABLE." : "NOT BICOLORABLE.");
        for(int i = 0; i < graph.numVertices; ++i)
            free(graph.edges[i]);
        free(graph.edges);
        free(graph.edgesCount);
        free(graph.color);
        free(graph.visited);
    }
	return 0;
}
