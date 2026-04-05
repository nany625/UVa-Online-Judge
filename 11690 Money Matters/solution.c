#include <stdio.h>
#include <stdbool.h>
#define MAXN 10000

int root[MAXN], rank[MAXN], sum[MAXN];

void init(int n) {
    for(int i = 0; i < n; ++i)
        rank[root[i] = i] = 0;
}

int find(int x) {
    return root[x] == x ? x : (root[x] = find(root[x]));
}

void unite(int rootX, int rootY) {
    if(rank[rootX] > rank[rootY]) {
        sum[rootX] += sum[rootY];
        root[rootY] = rootX;
    } else if(rank[rootX] < rank[rootY]) {
        sum[rootY] += sum[rootX];
        root[rootX] = rootY;
    } else {
        sum[rootX] += sum[rootY];
        ++rank[root[rootY] = rootX];
    }
}

int main() {
	int N;
	scanf("%d", &N);
	while(N--) {
        int n, m;
        scanf("%d %d", &n, &m);
        init(n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &sum[i]);
        while(m--) {
            int x, y;
            scanf("%d %d", &x, &y);
            int rootX = find(x), rootY = find(y);
            if(rootX != rootY)
                unite(rootX, rootY);
        }
        bool possible = true;
        for(int i = 0; i < n && possible; ++i)
            possible = sum[find(i)] == 0;
        puts(possible ? "POSSIBLE" : "IMPOSSIBLE");
	}
	return 0;
}
