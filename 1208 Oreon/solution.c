#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int parent, child, weight;
} Edge;

int compare(const void *a, const void *b) {
	Edge *e1 = (Edge*)a;
	Edge *e2 = (Edge*)b;
	if(e1->weight != e2->weight)
    	return e1->weight > e2->weight;
    if(e1->parent == e2->parent)
    	return e1->child > e2->child;
    return e1->parent > e2->parent;
}

int findRoot(int *root, int child) {
    return root[child] == child ? child : (root[child] = findRoot(root, root[child]));
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
            int root1 = findRoot(root, edges[j].parent), root2 = findRoot(root, edges[j].child);
            if(root1 != root2) {
                printf("%c-%c %d\n", edges[j].parent + 'A', edges[j].child + 'A', edges[j].weight);
                root[root2] = root1;
                ++count;
            }
        }
        free(edges);
    }
    return 0;
}
