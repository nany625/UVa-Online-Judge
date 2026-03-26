#include <stdio.h>
#include <stdlib.h>
#define MAXV 100
#define MAXE 4950

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAXE];
int root[MAXV + 1], rank[MAXV + 1];

void init(int V) {
    for(int n = 1; n <= V; ++n)
        rank[root[n] = n] = 0;
}

int find(int x) {
    return root[x] == x ? x : (root[x] = find(root[x]));
}

void unite(int rootX, int rootY) {
    if(rank[rootX] > rank[rootY])
        root[rootY] = rootX;
    else if(rank[rootX] < rank[rootY])
        root[rootX] = rootY;
    else
        ++rank[root[rootY] = rootX];
}

void kruskal(int V, int E, int start, int *slimness) {
    init(V);
    int count = 0;
    for(int i = start; i < E; ++i) {
        int root1 = find(edges[i].u), root2 = find(edges[i].v);
        if(root1 != root2) {
            unite(root1, root2);
            ++count;
        }
        if(count == V - 1) {
            *slimness = *slimness < edges[i].w - edges[start].w ? *slimness : edges[i].w - edges[start].w;
            return;
        }
    }
}

int compare(const void *a, const void *b) {
    return ((Edge*)a)->w > ((Edge*)b)->w;
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) && n != 0) {
        for(int i = 0; i < m; ++i)
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        qsort(edges, m, sizeof(Edge), compare);
        int slimness = 10000;
        for(int i = 0; i <= m - n + 1; ++i)
            kruskal(n, m, i, &slimness);
        printf("%d\n", slimness == 10000 ? -1 : slimness);
    }
	return 0;
}
