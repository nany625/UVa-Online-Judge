#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 750

typedef struct {
	int x, y;
} Coordinate;

typedef struct {
	int parent, child, weight;
} Edge;

Edge edges[MAXV * (MAXV - 1) >> 1];
int root[MAXV];

int dist(Coordinate c1, Coordinate c2) {
	return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
}

int findRoot(int child) {
	return root[child] == child ? child : (root[child] = findRoot(root[child]));
}

int compare(const void *a, const void *b) {
	return ((Edge*)a)->weight > ((Edge*)b)->weight;
}

int main() {
	int N;
	while(scanf("%d", &N) == 1) {
		Coordinate buildings[N];
		for(int i = 0; i < N; ++i) {
			scanf("%d %d", &buildings[i].x, &buildings[i].y);
			root[i] = i;
		}
		int count = 0;
		for(int i = 0; i < N - 1; ++i) {
			for(int j = i + 1; j < N; ++j)
				edges[count++] = (Edge){i, j, dist(buildings[i], buildings[j])};
		}
		qsort(edges, count, sizeof(Edge), compare);
		int M;
		scanf("%d", &M);
		count = 0;
		while(M--) {
			int label1, label2;
			scanf("%d %d", &label1, &label2);
			int root1 = findRoot(label1 - 1), root2 = findRoot(label2 - 1);
			if(root1 != root2) {
				root[root2] = root1;
				++count;
			}
		}
		double length = 0;
		for(int i = 0; count < N - 1; ++i) {
			int root1 = findRoot(edges[i].parent), root2 = findRoot(edges[i].child);
			if(root1 != root2) {
				length += sqrt(edges[i].weight);
				root[root2] = root1;
				++count;
			}
		}
		printf("%.2lf\n", length);
	}
	return 0;
}
