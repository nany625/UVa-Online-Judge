#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXP 500

typedef struct {
	int x, y;
} Coordinate;

typedef struct {
	int parent, child;
	double weight;
} Edge;

Edge edges[MAXP * (MAXP - 1) >> 1];
int root[MAXP];

int compare(const void *a, const void *b) {
	return ((Edge*)a)->weight > ((Edge*)b)->weight;
}

double dist(Coordinate c1, Coordinate c2) {
	return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

int findRoot(int child) {
	return root[child] == child ? child : (root[child] = findRoot(root[child]));
}

int main() {
	int N;
	scanf("%d", &N);
	while(N--) {
		int S, P;
		scanf("%d %d", &S, &P);
		Coordinate outposts[P];
		for(int i = 0; i < P; ++i) {
			scanf("%d %d", &outposts[i].x, &outposts[i].y);
			root[i] = i;
		}
		int count = 0;
		for(int i = 0; i < P - 1; ++i) {
			for(int j = i + 1; j < P; ++j)
				edges[count++] = (Edge){i, j, dist(outposts[i], outposts[j])};
		}
		qsort(edges, count, sizeof(Edge), compare);
		double MST[P - 1];
		count = 0;
		for(int i = 0; count < P - 1; ++i) {
			int root1 = findRoot(edges[i].parent), root2 = findRoot(edges[i].child);
			if(root1 != root2) {
				root[root2] = root1;
				MST[count++] = edges[i].weight;
			}
		}
		printf("%.2lf\n", MST[P - 1 - S]);
	}
	return 0;
}
