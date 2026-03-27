#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 100

typedef struct {
    double x, y;
} Coordinate;

typedef struct {
    int u, v;
    double w;
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

double dist(Coordinate c1, Coordinate c2) {
    return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
}

int compare(const void *a, const void *b) {
    double diff = ((Edge*)a)->w - ((Edge*)b)->w;
    return (diff > 0) > (diff < 0);
}

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int n;
        scanf("%d", &n);
        init(n);
        Coordinate freckles[n];
        for(int i = 0; i < n; ++i)
            scanf("%lf %lf", &freckles[i].x, &freckles[i].y);
        int size = 0;
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j)
                edges[size++] = (Edge){i, j, dist(freckles[i], freckles[j])};
        }
        qsort(edges, size, sizeof(Edge), compare);
        int count = 0;
        double length = 0;
        for(int i = 0; count < n - 1; ++i) {
            int root1 = find(edges[i].u), root2 = find(edges[i].v);
            if(root1 != root2) {
                length += sqrt(edges[i].w);
                unite(root1, root2);
                ++count;
            }
        }
        printf("%.2f\n", length);
        if(cases)
            putchar('\n');
    }
    return 0;
}
