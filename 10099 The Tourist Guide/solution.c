#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int u, v, w;
} Edge;

int root[101];

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
}

int compare(const void *a, const void *b) {
	return ((Edge*)a)->w < ((Edge*)b)->w;
}

int main() {
	int scenario = 0, N, R;
	while(scanf("%d %d", &N, &R) == 2) {
		for(int i = 1; i <= N; ++i)
			root[i] = i;
		Edge edges[R];
		for(int i = 0; i < R; ++i)
			scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		qsort(edges, R, sizeof(Edge), compare);
		int S, D, T;
		scanf("%d %d %d", &S, &D, &T);
		for(int i = 0; i < R; ++i) {
			int root1 = find(edges[i].u), root2 = find(edges[i].v);
			if(root1 != root2)
				root[root2] = root1;
			if(find(S) == find(D)) {
				printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", ++scenario, (int)ceil(T / (edges[i].w - 1.0)));
				break;
			}
		}
	}
	return 0;
}
