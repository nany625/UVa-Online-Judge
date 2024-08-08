#include <stdio.h>

int findRoot(int *root, int child) {
    if(root[child] == child)
        return child;
    return root[child] = findRoot(root, root[child]);
}

int main() {
    int cases = 0, n, m;
    while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
        int root[n + 1];
        for(int i = 1; i <= n; ++i)
            root[i] = i;
        while(m--) {
            int i, j;
            scanf("%d %d", &i, &j);
            int rootI = findRoot(root, i), rootJ = findRoot(root, j);
            n -= rootI != rootJ;
            root[rootI] = root[rootJ];
        }
        printf("Case %d: %d\n", ++cases, n);
    }
	return 0;
}
