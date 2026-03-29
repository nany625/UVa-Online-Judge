#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(int *root, int *rank, int n) {
    for(int i = 1; i <= n; ++i)
        rank[root[i] = i] = 0;
}

int find(int *root, int x) {
    return root[x] == x ? x : (root[x] = find(root, root[x]));
}

void unite(int *root, int *rank, int rootX, int rootY) {
    if(rank[rootX] > rank[rootY])
        root[rootY] = rootX;
    else if(rank[rootX] < rank[rootY])
        root[rootX] = rootY;
    else
        ++rank[root[rootY] = rootX];
}

int main() {
    int cases;
    scanf("%d", &cases);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(cases--) {
        int N;
        scanf("%d ", &N);
        int root[N + 1], rank[N + 1], nets = N;
        init(root, rank, N);
        while(getline(&buffer, &bufsize, stdin) != -1 && buffer[0] != '\n') {
            char *token = strtok(buffer, " ");
            while(token) {
                int root1 = find(root, atoi(token));
                token = strtok(NULL, " ");
                int root2 = find(root, atoi(token));
                if(root1 != root2) {
                    unite(root, rank, root1, root2);
                    --nets;
                }
                token = strtok(NULL, " ");
            }
        }
        printf("%d\n", nets);
        if(cases)
            putchar('\n');
    }
    free(buffer);
	return 0;
}
