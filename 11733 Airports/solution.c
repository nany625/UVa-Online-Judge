#include <stdio.h>
#include <stdlib.h>
#define MAXV 10000
#define MAXE 100000

typedef struct {
	int u, v, w;
} Edge;

Edge edges[MAXE];
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

int compare(const void *a, const void *b) {
    return ((Edge*)a)->w > ((Edge*)b)->w;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N, M, A;
        scanf("%d %d %d", &N, &M, &A);
        init(N);
        for(int j = 0; j < M; ++j)
            scanf("%d %d %d", &edges[j].u, &edges[j].v, &edges[j].w);
        qsort(edges, M, sizeof(Edge), compare);
        int cost = 0, airports = N, count = 0;
        for(int j = 0; j < M && count < N - 1; ++j) {
            int root1 = find(edges[j].u), root2 = find(edges[j].v);
            if(root1 != root2) {
                if(A > edges[j].w) {
                    cost += edges[j].w;
                    --airports;
                }
                unite(root1, root2);
                ++count;
            }
        }
        printf("Case #%d: %d %d\n", i, cost + airports * A, airports);
    }
    return 0;
}
