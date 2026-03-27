#include <stdio.h>
#include <stdlib.h>
#define MAXV 200000
#define MAXE 200000

typedef struct {
	int u, v, w;
} Edge;

Edge edges[MAXE];
int root[MAXV], rank[MAXV];

void init(int V) {
    for(int n = 0; n < V; ++n)
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

int compare(const void *a, const void *b) {
	return ((Edge*)a)->w > ((Edge*)b)->w;
}

int main() {
	int m, n;
	while(scanf("%d %d", &m, &n) && m != 0) {
        init(m);
	    for(int i = 0; i < n; ++i)
	        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
	    qsort(edges, n, sizeof(Edge), compare);
	    int save = 0;
	    for(int i = 0; i < n; ++i) {
	        int root1 = find(edges[i].u), root2 = find(edges[i].v);
	        if(root1 != root2)
	            unite(root1, root2);
	        else
	            save += edges[i].w;
	    }
	    printf("%d\n", save);
	}
	return 0;
}
