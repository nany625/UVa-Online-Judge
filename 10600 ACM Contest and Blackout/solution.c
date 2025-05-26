#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXV 99

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAXV * (MAXV - 1) >> 1];
int root[MAXV + 1];

void init(int n) {
    for(int i = 1; i <= n; ++i)
        root[i] = i;
}

int find(int x) {
    return root[x] == x ? x : (root[x] = find(root[x]));
}

int compare(const void *a, const void *b) {
    return ((Edge*)a)->w > ((Edge*)b)->w;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        for(int i = 0; i < M; ++i)
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        qsort(edges, M, sizeof(Edge), compare);
        init(N);
        int edgeID[N - 1], cost1 = 0, count = 0;
        bool used[M];
        memset(used, 0, sizeof(used));
        for(int i = 0; count < N - 1; ++i) {
            int root1 = find(edges[i].u), root2 = find(edges[i].v);
            if(root1 != root2) {
                root[root2] = root1;
                cost1 += edges[i].w;
                edgeID[count++] = i;
                used[i] = true;
            }
        }
        int cost2 = 30000;
        for(int i = 0; i < count; ++i) {
            init(N);
            for(int j = 0; j < count; ++j) {
                if(j != i) {
                    int root1 = find(edges[edgeID[j]].u), root2 = find(edges[edgeID[j]].v);
                    root[root2] = root1;
                }
            }
            int temp = cost1 - edges[edgeID[i]].w;
            for(int j = 0; j < M; ++j) {
                if(!used[j]) {
                    int root1 = find(edges[j].u), root2 = find(edges[j].v);
                    if(root1 != root2) {
                        cost2 = cost2 < temp + edges[j].w ? cost2 : temp + edges[j].w;
                        break;
                    }
                }
            }
        }
        printf("%d %d\n", cost1, cost2);
    }
	return 0;
}
