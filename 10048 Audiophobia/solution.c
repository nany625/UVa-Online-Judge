#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int u, v, w;
} Edge;

Edge edges[1000];
int root[101];

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
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
		    for(int i = 1; i <= C; ++i)
			    root[i] = i;
			bool noPath = false;
			for(int i = 0; i < S && !noPath; ++i) {
    			int root1 = find(edges[i].u), root2 = find(edges[i].v);
    			if(root1 != root2)
    				root[root2] = root1;
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
