#include <stdio.h>

int root[26], rank[26];

void init(int n) {
    for(int i = 0; i < n; ++i)
        rank[root[i] = i] = 0;
}

int find(int x) {
	return root[x] == x ? x : (root[x] = find(root[x]));
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
                --subgraphs;
                if(rank[root1] > rank[root2])
                    root[root2] = root1;
                else if(rank[root1] < rank[root2])
                    root[root1] = root2;
                else
                    ++rank[root[root2] = root1];
            }
        }
        printf("%d\n", subgraphs);
        if(cases)
            putchar('\n');
    }
    return 0;
}
