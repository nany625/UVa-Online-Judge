#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXV 1000
#define MAXE 25000

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
	int n, m;
	while(scanf("%d %d", &n, &m) && n != 0) {
		init(n);
		for(int i = 0; i < m; ++i)
			scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		qsort(edges, m, sizeof(Edge), compare);
		bool isForest = true;
		for(int i = 0; i < m; ++i) {
			int root1 = find(edges[i].u), root2 = find(edges[i].v);
			if(root1 != root2)
				unite(root1, root2);
			else {
				if(!isForest)
					putchar(' ');
				printf("%d", edges[i].w);
				isForest = false;
			}
		}
		if(isForest)
			puts("forest");
		else
			putchar('\n');
	}
	return 0;
}
