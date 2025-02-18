#include <stdio.h>
#include <stdlib.h>
#define MAXV 200000
#define MAXE 200000

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
	int m, n;
	while(scanf("%d %d", &m, &n) && m != 0) {
	    int cost = 0;
	    for(int i = 0; i < n; ++i)
	        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
	    qsort(edges, n, sizeof(Edge), compare);
	    for(int i = 0; i < m; ++i)
	        root[i] = i;
	    int save = 0;
	    for(int i = 0; i < n; ++i) {
	        int root1 = find(edges[i].u), root2 = find(edges[i].v);
	        if(root1 != root2)
	            root[root2] = root1;
	        else
	            save += edges[i].w;
	    }
	    printf("%d\n", save);
	}
	return 0;
}
