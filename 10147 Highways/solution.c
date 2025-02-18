#include <stdio.h>
#include <stdlib.h>
#define MAXV 750

typedef struct {
    int x, y;
} Coordinate;

typedef struct {
	int u, v, w;
} Edge;

Edge edges[MAXV * (MAXV - 1) >> 1];
int root[MAXV + 1];

int dist(Coordinate c1, Coordinate c2) {
    return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
}

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
}

int compare(const void *a, const void *b) {
    Edge *e1 = (Edge*)a;
    Edge *e2 = (Edge*)b;
    if(e1->w != e2->w)
	    return e1->w > e2->w;
	if(e1->u != e2->u)
	    return e1->u > e2->u;
	return e1->v > e2->v;
}

int main() {
	int cases;
	scanf("%d", &cases);
	while(cases--) {
	    int N;
	    scanf("%d", &N);
	    Coordinate towns[N];
	    for(int i = 0; i < N; ++i) {
	        scanf("%d %d", &towns[i].x, &towns[i].y);
	        root[i + 1] = i + 1;
	    }
	    int M;
	    scanf("%d", &M);
	    int count = 0;
	    while(M--) {
	        int town1, town2;
	        scanf("%d %d", &town1, &town2);
	        int root1 = find(town1), root2 = find(town2);
	        if(root1 != root2) {
	            root[root2] = root1;
	            ++count;
	        }
	    }
	    if(count == N - 1)
	        puts("No new highways need");
	    else {
	        int size = 0;
    	    for(int i = 0; i < N - 1; ++i) {
    	        for(int j = i + 1; j < N; ++j)
    	            edges[size++] = (Edge){i + 1, j + 1, dist(towns[i], towns[j])};
    	    }
    	    qsort(edges, size, sizeof(Edge), compare);
    	    for(int i = 0; count < N - 1; ++i) {
    	        int root1 = find(edges[i].u), root2 = find(edges[i].v);
    	        if(root1 != root2) {
    	            printf("%d %d\n", edges[i].u, edges[i].v);
    	            root[root2] = root1;
    	            ++count;
    	        }
    	    }
	    }
	    if(cases)
	        putchar('\n');
	}
	return 0;
}
