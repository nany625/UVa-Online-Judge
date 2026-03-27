#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int u, v, w;
} Edge;

int root[101], rank[101];

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
	int scenario = 0, N, R;
	while(scanf("%d %d", &N, &R) == 2) {
		init(N);
		Edge edges[R];
		for(int i = 0; i < R; ++i)
			scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		qsort(edges, R, sizeof(Edge), compare);
		int S, D, T;
		scanf("%d %d %d", &S, &D, &T);
		for(int i = 0; i < R; ++i) {
			int root1 = find(edges[i].u), root2 = find(edges[i].v);
			if(root1 != root2)
				unite(root1, root2);
			if(find(S) == find(D)) {
				printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", ++scenario, (int)ceil(T / (edges[i].w - 1.0)));
				break;
			}
		}
	}
	return 0;
}
