#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

void init(int *root, int *rank, int V) {
    for(int n = 0; n < V; ++n)
        rank[root[n] = n] = 0;
}

int find(int *root, int x) {
    return root[x] == x ? x : (root[x] = find(root, root[x]));
}

void unite(int *root, int *rank, int rootX, int rootY) {
    if(rank[rootX] > rank[rootY])
        root[rootY] = rootX;
    else if(rank[rootX] < rank[rootY])
        root[rootX] = rootY;
    else
        ++rank[root[rootY] = rootX];
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
    for(int i = 1; i <= cases; ++i) {
        printf("Case %d:\n", i);
        int cities;
        scanf("%d", &cities);
        int root[cities], rank[cities], size = 0;
        init(root, rank, cities);
        Edge *edges = NULL;
        for(int j = 0; j < cities; ++j) {
            for(int k = 0; k < cities; ++k) {
                int w;
                if(k < cities - 1)
                    scanf("%d,", &w);
                else
                    scanf("%d", &w);
                if(w > 0 && j < k) {
                    edges = (Edge*)realloc(edges, (size + 1) * sizeof(Edge));
                    edges[size++] = (Edge){j, k, w};
                }
            }
        }
        qsort(edges, size, sizeof(Edge), compare);
        int count = 0;
        for(int j = 0; count < cities - 1; ++j) {
            int root1 = find(root, edges[j].u), root2 = find(root, edges[j].v);
            if(root1 != root2) {
                printf("%c-%c %d\n", edges[j].u + 'A', edges[j].v + 'A', edges[j].w);
                unite(root, rank, root1, root2);
                ++count;
            }
        }
        free(edges);
    }
    return 0;
}
