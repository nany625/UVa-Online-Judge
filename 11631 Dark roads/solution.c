#include <stdio.h>
#include <stdlib.h>
#define MAXV 200000
#define MAXE 200000

typedef struct {
	int parent, child, weight;
} Edge;

Edge edges[MAXE];
int root[MAXV];

int findRoot(int child) {
	return root[child] == child ? child : (root[child] = findRoot(root[child]));
}

int compare(const void *a, const void *b) {
	return ((Edge*)a)->weight > ((Edge*)b)->weight;
}

int main() {
	int m, n;
	while(scanf("%d %d", &m, &n) && m != 0) {
	    int cost = 0;
	    for(int i = 0; i < n; ++i)
	        scanf("%d %d %d", &edges[i].parent, &edges[i].child, &edges[i].weight);
	    qsort(edges, n, sizeof(Edge), compare);
	    for(int i = 0; i < m; ++i)
	        root[i] = i;
	    int save = 0;
	    for(int i = 0; i < n; ++i) {
	        int root1 = findRoot(edges[i].parent), root2 = findRoot(edges[i].child);
	        if(root1 != root2)
	            root[root2] = root1;
	        else
	            save += edges[i].weight;
	    }
	    printf("%d\n", save);
	}
	return 0;
}
