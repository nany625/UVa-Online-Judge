#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXN 199

short numVertices, **edges, edgesCount[MAXN];
char color[MAXN];

void dfs(int startVertex, char c, bool *bicolorable) {
    color[startVertex] = c;
    for(int i = 0; i < edgesCount[startVertex]; ++i) {
        if(color[edges[startVertex][i]] == '\0')
            dfs(edges[startVertex][i], c == '0' ? '1' : '0', bicolorable);
        else if(color[edges[startVertex][i]] == c) {
            *bicolorable = false;
            return;
        }
    }
}

int main() {
    edges = (short**)malloc((MAXN + 1) * sizeof(short*));
    for(int i = 0; i < MAXN; ++i)
        edges[i] = NULL;
    short n;
    while(scanf("%hd", &n) && n != 0) {
        short l;
        scanf("%hd", &l);
        memset(edgesCount, 0, sizeof(edgesCount));
        short startVertex;
        while(l--) {
            short a, b;
            scanf("%hd %hd", &a, &b);
            edges[a] = (short*)realloc(edges[a], (edgesCount[a] + 1) * sizeof(short));
            edges[a][edgesCount[a]++] = b;
            edges[b] = (short*)realloc(edges[b], (edgesCount[b] + 1) * sizeof(short));
            startVertex = edges[b][edgesCount[b]++] = a;
        }
        memset(color, '\0', sizeof(color));
        bool bicolorable = true;
        dfs(startVertex, '0', &bicolorable);
        puts(bicolorable ? "BICOLORABLE." : "NOT BICOLORABLE.");
    }
    for(int i = 0; i < MAXN; ++i)
        free(edges[i]);
    free(edges);
	return 0;
}
