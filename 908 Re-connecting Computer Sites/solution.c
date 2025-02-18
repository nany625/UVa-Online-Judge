#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXV 1000000

typedef struct {
	int u, v, w;
} Edge;

int root[MAXV + 1];

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
}

int compare(const void *a, const void *b) {
	return ((Edge*)a)->w > ((Edge*)b)->w;
}

int main() {
	int N;
	bool firstCase = true;
	while(scanf("%d", &N) == 1) {
		if(!firstCase)
		    putchar('\n');
		for(int i = 1; i <= N; ++i)
		    root[i] = i;
		int cost = 0, w;
		for(int i = 1; i < N; ++i) {
		    scanf("%*d %*d %d", &w);
		    cost += w;
		}
		printf("%d\n", cost);
		int K;
		scanf("%d", &K);
		Edge *edges = (Edge*)malloc(K * sizeof(Edge));
		for(int i = 0; i < K; ++i)
		    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		int M;
		scanf("%d", &M);
		edges = (Edge*)realloc(edges, (K + M) * sizeof(Edge));
		for(int i = K; i < K + M; ++i)
		    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		qsort(edges, K + M, sizeof(Edge), compare);
		int count = 0;
		cost = 0;
		for(int i = 0; count < N - 1; ++i) {
		    int root1 = find(edges[i].u), root2 = find(edges[i].v);
		    if(root1 != root2) {
		        cost += edges[i].w;
		        root[root2] = root1;
		        ++count;
		    }
		}
		printf("%d\n", cost);
		free(edges);
		firstCase = false;
	}
	return 0;
}
