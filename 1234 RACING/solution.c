#include <stdio.h>
#include <stdlib.h>
#define MAXV 9999
#define MAXE 99999

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

int compare(const void *a, const void *b) {
	return ((Edge*)a)->w < ((Edge*)b)->w;
}

int main() {
	int c;
	scanf("%d", &c);
	while(c--) {
	    int n, m;
	    scanf("%d %d", &n, &m);
	    for(int i = 0; i < m; ++i)
	        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
	    qsort(edges, m, sizeof(Edge), compare);
	    init(n);
	    int cost = 0;
	    for(int i = 0; i < m; ++i) {
	        int root1 = find(edges[i].u), root2 = find(edges[i].v);
	        if(root1 != root2)
	            unite(root1, root2);
	        else
	            cost += edges[i].w;
	    }
	    printf("%d\n", cost);
	}
	return 0;
}
