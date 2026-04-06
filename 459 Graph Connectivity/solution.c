#include <stdio.h>

int root[26], rank[26];

void init(int n) {
    for(int i = 0; i < n; ++i)
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
    int cases;
    scanf("%d ", &cases);
    char line[4];
    while(cases--) {
        fgets(line, sizeof(line), stdin);
        int subgraphs = line[0] - 'A' + 1;
        init(subgraphs);
        while(fgets(line, sizeof(line), stdin) && line[0] != '\n') {
            int root1 = find(line[0] - 'A'), root2 = find(line[1] - 'A');
            if(root1 != root2) {
                unite(root1, root2);
                --subgraphs;
            }
        }
        printf("%d\n", subgraphs);
        if(cases)
            putchar('\n');
    }
    return 0;
}
