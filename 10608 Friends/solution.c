#include <stdio.h>
#define MAXN 30000

int root[MAXN + 1], depth[MAXN + 1];

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
}

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int N, M;
        scanf("%d %d", &N, &M);
        for(int n = 1; n <= N; ++n)
            depth[root[n] = n] = 1;
        int max = 1;
        while(M--) {
            int A, B;
            scanf("%d %d", &A, &B);
            int rootA = find(A), rootB = find(B);
            if(rootA != rootB) {
                depth[rootA] += depth[rootB];
                max = max > depth[rootA] ? max : depth[rootA];
                root[rootB] = rootA;
            }
        }
        printf("%d\n", max);
    }
	return 0;
}
