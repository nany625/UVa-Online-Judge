#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXV 1000
#define MAXE 25000

typedef struct {
	int u, v, w;
} Edge;

Edge edges[MAXE];
int root[MAXV];

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
}

int compare(const void *a, const void *b) {
	return ((Edge*)a)->w > ((Edge*)b)->w;
}

int main() {
	int n, m;
	while(scanf("%d %d", &n, &m) && n != 0) {
		for(int i = 0; i < n; ++i)
			root[i] = i;
		for(int i = 0; i < m; ++i)
			scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		qsort(edges, m, sizeof(Edge), compare);
		bool isForest = true;
		for(int i = 0; i < m; ++i) {
			int root1 = find(edges[i].u), root2 = find(edges[i].v);
			if(root1 != root2)
				root[root2] = root1;
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
