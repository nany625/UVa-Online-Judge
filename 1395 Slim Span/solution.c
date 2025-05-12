#include <stdio.h>
#include <stdlib.h>
#define MAXV 100
#define MAXE 4950

typedef struct {
    int u, v, w;
} Edge;

int root[MAXV + 1];
Edge edges[MAXE];

int find(int x) {
    return root[x] == x ? x : (root[x] = find(root[x]));
}

int compare(const void *a, const void *b) {
    return ((Edge*)a)->w > ((Edge*)b)->w;
}

void kruskal(int V, int E, int start, int *slimness) {
    for(int i = 1; i <= V; ++i)
        root[i] = i;
    int count = 0;
    for(int i = start; i < E; ++i) {
        int root1 = find(edges[i].u), root2 = find(edges[i].v);
        if(root1 != root2) {
            root[root2] = root1;
            ++count;
        }
        if(count == V - 1) {
            *slimness = *slimness < edges[i].w - edges[start].w ? *slimness : edges[i].w - edges[start].w;
            return;
        }
    }
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) && n != 0) {
        for(int i = 0; i < m; ++i)
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        qsort(edges, m, sizeof(Edge), compare);
        int slimness = 10000;
        for(int i = 0; i < m; ++i)
            kruskal(n, m, i, &slimness);
        printf("%d\n", slimness == 10000 ? -1 : slimness);
    }
	return 0;
}
