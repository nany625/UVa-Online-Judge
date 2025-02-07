#include <stdio.h>
#define MAX_NUM 100000

int root[MAX_NUM + 1], refusals;

void init() {
    for(int n = 0; n <= MAX_NUM; ++n)
        root[n] = n;
    refusals = 0;
}

int findRoot(int child) {
    return root[child] == child ? child : (root[child] = findRoot(root[child]));
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
            int rootX = findRoot(x), rootY = findRoot(y);
            if(rootX == rootY)
                ++refusals;
            else
                root[rootY] = rootX;
        }
    }
    return 0;
}
