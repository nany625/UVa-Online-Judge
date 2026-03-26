#include <stdio.h>
#define MAX_NUM 100000

int root[MAX_NUM + 1], rank[MAX_NUM + 1], refusals;

void init() {
    for(int i = 0; i <= MAX_NUM; ++i)
        rank[root[i] = i] = 0;
    refusals = 0;
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
    init();
    int x;
    while(scanf("%d", &x) == 1) {
        if(x == -1) {
            printf("%d\n", refusals);
            init();
        } else {
            int y;
            scanf("%d", &y);
            int rootX = find(x), rootY = find(y);
            if(rootX == rootY)
                ++refusals;
            else
                unite(rootX, rootY);
        }
    }
    return 0;
}
