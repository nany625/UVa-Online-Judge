#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int u, v, w;
} Edge;

Edge edges[1000];
int root[101], rank[101];

void init(int V) {
    for(int n = 1; n <= V; ++n)
        rank[root[n] = n] = 0;
}

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
}

void unite(int rootX, int rootY) {
    if(rank[rootX] > rank[rootY])
        root[rootY] = rootX;
    else if(rank[rootX] < rank[rootY])
        root[rootX] = rootY;
    else
        ++rank[root[rootY] = rootX];
}

int compare(const void *a, const void *b) {
	return ((Edge*)a)->w > ((Edge*)b)->w;
}

int main() {
	int cases = 0, C, S, Q;
	while(scanf("%d %d %d", &C, &S, &Q) && C != 0) {
	    if(cases)
	        putchar('\n');
	    printf("Case #%d\n", ++cases);
		for(int i = 0; i < S; ++i)
			scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		qsort(edges, S, sizeof(Edge), compare);
		while(Q--) {
		    int c1, c2;
		    scanf("%d %d", &c1, &c2);
		    init(C);
			bool noPath = false;
			for(int i = 0; i < S && !noPath; ++i) {
    			int root1 = find(edges[i].u), root2 = find(edges[i].v);
    			if(root1 != root2)
    				unite(root1, root2);
    			if(find(c1) == find(c2)) {
    			    printf("%d\n", edges[i].w);
    			    noPath = true;
    			}
    		}
    		if(!noPath)
    		    puts("no path");
		}
	}
	return 0;
}
