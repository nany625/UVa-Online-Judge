#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int compare(const void *a, const void *b) {
	Edge *e1 = (Edge*)a;
	Edge *e2 = (Edge*)b;
	if(e1->w != e2->w)
    	return e1->w > e2->w;
    if(e1->u != e2->u)
        return e1->u > e2->u;
    return e1->v > e2->v;
}

int find(int *root, int x) {
    return root[x] == x ? x : (root[x] = find(root, root[x]));
}

int main() {
    int cases;
    scanf("%d", &cases);
    for(int i = 1; i <= cases; ++i) {
        printf("Case %d:\n", i);
        int cities;
        scanf("%d", &cities);
        int root[cities], size = 0;
        Edge *edges = NULL;
        for(int j = 0; j < cities; ++j) {
            root[j] = j;
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
                root[root2] = root1;
                ++count;
            }
        }
        free(edges);
    }
    return 0;
}
