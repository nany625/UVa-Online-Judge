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
int root[MAXV + 1], rank[MAXV + 1];

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

int dist(Coordinate c1, Coordinate c2) {
    return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
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
        init(N);
	    Coordinate towns[N];
	    for(int i = 0; i < N; ++i)
	        scanf("%d %d", &towns[i].x, &towns[i].y);
	    int M;
	    scanf("%d", &M);
	    int count = 0;
	    while(M--) {
	        int town1, town2;
	        scanf("%d %d", &town1, &town2);
	        int root1 = find(town1), root2 = find(town2);
	        if(root1 != root2) {
	            unite(root1, root2);
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
    	            unite(root1, root2);
    	            ++count;
    	        }
    	    }
	    }
	    if(cases)
	        putchar('\n');
	}
	return 0;
}
