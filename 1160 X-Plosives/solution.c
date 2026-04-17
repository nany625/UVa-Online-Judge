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

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        if(rank[x] > rank[y])
            root[y] = x;
        else if(rank[x] < rank[y])
            root[x] = y;
        else
            ++rank[root[y] = x];
    } else
        ++refusals;
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
            unite(x, y);
        }
    }
    return 0;
}
