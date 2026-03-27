#include <stdio.h>
#define MAXN 50000

int root[MAXN + 1], rank[MAXN + 1];

void init(int n) {
    for(int i = 1; i <= n; ++i)
        rank[root[i] = i] = 0;
}

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
}

void unite(int rootX, int rootY) {
    if(rank[rootX] > rank[rootY])
        root[rootY] = rootX;
    else if(rank[rootX] < rank[rootY])
        root[rootX] = rootY;
    else
        ++rank[root[rootY] = rootX];
}

int main() {
    int cases = 0, n, m;
    while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
        init(n);
        while(m--) {
            int i, j;
            scanf("%d %d", &i, &j);
            int rootI = find(i), rootJ = find(j);
            if(rootI != rootJ) {
                --n;
                unite(rootI, rootJ);
            }
        }
        printf("Case %d: %d\n", ++cases, n);
    }
	return 0;
}
