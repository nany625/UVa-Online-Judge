#include <stdio.h>
#define MAX_NUM 50000

int root[MAX_NUM + 1];

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
}

int main() {
    int cases = 0, n, m;
    while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
        for(int i = 1; i <= n; ++i)
            root[i] = i;
        while(m--) {
            int i, j;
            scanf("%d %d", &i, &j);
            int rootI = find(i), rootJ = find(j);
            n -= rootI != rootJ;
            root[rootJ] = rootI;
        }
        printf("Case %d: %d\n", ++cases, n);
    }
	return 0;
}
