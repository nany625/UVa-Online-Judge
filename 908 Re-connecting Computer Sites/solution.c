#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXV 1000000

typedef struct {
	int parent, child, weight;
} Edge;

int root[MAXV + 1];

int compare(const void *a, const void *b) {
	return ((Edge*)a)->weight > ((Edge*)b)->weight;
}

int findRoot(int child) {
	return root[child] == child ? child : (root[child] = findRoot(root[child]));
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
		    scanf("%d %d %d", &edges[i].parent, &edges[i].child, &edges[i].weight);
		int M;
		scanf("%d", &M);
		edges = (Edge*)realloc(edges, (K + M) * sizeof(Edge));
		for(int i = K; i < K + M; ++i)
		    scanf("%d %d %d", &edges[i].parent, &edges[i].child, &edges[i].weight);
		qsort(edges, K + M, sizeof(Edge), compare);
		int count = 0;
		cost = 0;
		for(int i = 0; count < N - 1; ++i) {
		    int root1 = findRoot(edges[i].parent), root2 = findRoot(edges[i].child);
		    if(root1 != root2) {
		        cost += edges[i].weight;
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
