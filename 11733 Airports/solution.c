#include <stdio.h>
#include <stdlib.h>
#define MAXV 10000
#define MAXE 100000

typedef struct {
    int parent, child, weight;
} Edge;

Edge edges[MAXE];
int root[MAXV + 1];

int findRoot(int child) {
    return root[child] == child ? child : (root[child] = findRoot(root[child]));
}

int compare(const void *a, const void *b) {
    return ((Edge*)a)->weight > ((Edge*)b)->weight;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N, M, A;
        scanf("%d %d %d", &N, &M, &A);
        for(int j = 0; j < M; ++j)
            scanf("%d %d %d", &edges[j].parent, &edges[j].child, &edges[j].weight);
        qsort(edges, M, sizeof(Edge), compare);
        for(int j = 1; j <= N; ++j)
            root[j] = j;
        int cost = 0, airports = N, count = 0;
        for(int j = 0; j < M && count < N - 1; ++j) {
            int root1 = findRoot(edges[j].parent), root2 = findRoot(edges[j].child);
            if(root1 != root2) {
                if(A > edges[j].weight) {
                    cost += edges[j].weight;
                    --airports;
                }
                root[root2] = root1;
                ++count;
            }
        }
        printf("Case #%d: %d %d\n", i, cost + airports * A, airports);
    }
    return 0;
}
