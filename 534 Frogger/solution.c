#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAXV 200

typedef struct {
	int x, y;
} Coordinate;

typedef struct {
	int u, v, w;
} Edge;

Edge edges[MAXV * (MAXV - 1) >> 1];
int root[MAXV];

int dist(Coordinate c1, Coordinate c2) {
	return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
}

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
}

int compare(const void *a, const void *b) {
	return ((Edge*)a)->w > ((Edge*)b)->w;
}

int main() {
	int cases = 0, n;
	while(scanf("%d", &n) && n != 0) {
		Coordinate stones[n];
		for(int i = 0; i < n; ++i)
			scanf("%d %d", &stones[i].x, &stones[i].y);
		int size = 0;
		for(int i = 0; i < n - 1; ++i) {
			for(int j = i + 1; j < n; ++j)
				edges[size++] = (Edge){i, j, dist(stones[i], stones[j])};
		}
		qsort(edges, size, sizeof(Edge), compare);
		for(int i = 0; i < n; ++i)
			root[i] = i;
		int i = 0;
		while(true) {
			int root1 = find(edges[i].u), root2 = find(edges[i].v);
			if(root1 != root2)
				root[root2] = root1;
			if(find(0) == find(1)) {
				printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++cases, sqrt(edges[i].w));
				break;
			}
			++i;
		}
	}
	return 0;
}
