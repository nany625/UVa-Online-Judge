#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 1000

typedef struct {
    int x, y;
} Coordinate;

typedef struct {
	int u, v, w;
} Edge;

Edge edges[MAXV * (MAXV - 1) >> 1];
int root[MAXV], rank[MAXV];

void init(int V) {
    for(int n = 0; n < V; ++n)
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
	return ((Edge*)a)->w > ((Edge*)b)->w;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
	    int n, r;
	    scanf("%d %d", &n, &r);
        init(n);
        Coordinate cities[n];
	    for(int j = 0; j < n; ++j)
	        scanf("%d %d", &cities[j].x, &cities[j].y);
	    int size = 0;
	    for(int j = 0; j < n - 1; ++j) {
	        for(int k = j + 1; k < n; ++k)
	            edges[size++] = (Edge){j, k, dist(cities[j], cities[k])};
	    }
	    qsort(edges, size, sizeof(Edge), compare);
	    r *= r;
	    double roadLen = 0, railroadLen = 0;
	    int count = 0, groups = n;
	    for(int j = 0; count < n - 1; ++j) {
	        int root1 = find(edges[j].u), root2 = find(edges[j].v);
	        if(root1 != root2) {
	            unite(root1, root2);
	            ++count;
	            if(edges[j].w <= r) {
	                roadLen += sqrt(edges[j].w);
	                --groups;
	            } else
	                railroadLen += sqrt(edges[j].w);
	        }
	    }
	    printf("Case #%d: %d %d %d\n", i, groups, (int)(roadLen + 0.5), (int)(railroadLen + 0.5));
	}
	return 0;
}
