#include <stdio.h>
#define MAX_NUM 30000

int root[MAX_NUM + 1], depth[MAX_NUM + 1];

int findRoot(int child) {
    return root[child] == child ? child : findRoot(root[child]);
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
            int rootA = findRoot(A), rootB = findRoot(B);
            if(rootA != rootB) {
                depth[root[rootA]] += depth[root[rootB]];
                max = max > depth[root[rootA]] ? max : depth[root[rootA]];
                root[rootB] = root[rootA];
            }
        }
        printf("%d\n", max);
    }
	return 0;
}
