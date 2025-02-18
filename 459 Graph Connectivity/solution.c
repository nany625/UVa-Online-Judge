#include <stdio.h>

int root[26];

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
        for(int n = 0; n < subgraphs; ++n)
            root[n] = n;
        while(fgets(line, sizeof(line), stdin) && line[0] != '\n') {
            int root1 = find(line[0] - 'A'), root2 = find(line[1] - 'A');
            if(root1 != root2) {
                --subgraphs;
                root[root2] = root1;
            }
        }
        printf("%d\n", subgraphs);
        if(cases)
            putchar('\n');
    }
    return 0;
}
