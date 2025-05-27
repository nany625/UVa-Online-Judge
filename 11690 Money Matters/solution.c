#include <stdio.h>
#include <stdbool.h>
#define MAXN 10000

int root[MAXN], sum[MAXN];

int find(int x) {
    return root[x] == x ? x : (root[x] = find(root[x]));
}

int main() {
	int N;
	scanf("%d", &N);
	while(N--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &sum[i]);
            root[i] = i;
        }
        while(m--) {
            int x, y;
            scanf("%d %d", &x, &y);
            int rootX = find(x), rootY = find(y);
            if(rootX != rootY) {
                sum[rootX] += sum[rootY];
                root[rootY] = rootX;
            }
        }
        bool possible = true;
        for(int i = 0; i < n && possible; ++i)
            possible = sum[find(i)] == 0;
        puts(possible ? "POSSIBLE" : "IMPOSSIBLE");
	}
	return 0;
}
