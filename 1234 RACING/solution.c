#include <stdio.h>
#include <stdlib.h>
#define MAXV 9999
#define MAXE 99999

typedef struct {
	int u, v, w;
} Edge;

Edge edges[MAXE];
int root[MAXV + 1];

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
}

int compare(const void *a, const void *b) {
	return ((Edge*)a)->w < ((Edge*)b)->w;
}

int main() {
	int c;
	scanf("%d", &c);
	while(c--) {
	    int n, m;
	    scanf("%d %d", &n, &m);
	    for(int i = 0; i < m; ++i)
	        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
	    qsort(edges, m, sizeof(Edge), compare);
	    for(int i = 1; i <= n; ++i)
	        root[i] = i;
	    int cost = 0;
	    for(int i = 0; i < m; ++i) {
	        int root1 = find(edges[i].u), root2 = find(edges[i].v);
	        if(root1 != root2)
	            root[root2] = root1;
	        else
	            cost += edges[i].w;
	    }
	    printf("%d\n", cost);
	}
	return 0;
}
