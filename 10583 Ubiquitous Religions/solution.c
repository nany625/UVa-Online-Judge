#include <stdio.h>
#define MAX_NUM 50000

int root[MAX_NUM + 1];

int findRoot(int child) {
    return root[child] == child ? child : (root[child] = findRoot(root[child]));
}

int main() {
    int cases = 0, n, m;
    while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
        for(int i = 1; i <= n; ++i)
            root[i] = i;
        while(m--) {
            int i, j;
            scanf("%d %d", &i, &j);
            int rootI = findRoot(i), rootJ = findRoot(j);
            n -= rootI != rootJ;
            root[rootJ] = root[rootI];
        }
        printf("Case %d: %d\n", ++cases, n);
    }
	return 0;
}
