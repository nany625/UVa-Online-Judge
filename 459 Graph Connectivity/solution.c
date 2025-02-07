#include <stdio.h>

int root[26];

int findRoot(int child) {
    return root[child] == child ? child : (root[child] = findRoot(root[child]));
}

int main() {
    int cases;
    scanf("%d  ", &cases);
    char line[4];
    while(cases--) {
        fgets(line, sizeof(line), stdin);
        int subgraphs = line[0] - 'A' + 1;
        for(int n = 0; n < subgraphs; ++n)
            root[n] = n;
        while(fgets(line, sizeof(line), stdin) && line[0] != '\n') {
            int node1 = line[0] - 'A', node2 = line[1] - 'A';
            int root1 = findRoot(node1), root2 = findRoot(node2);
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
