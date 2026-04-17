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

void unite(int *root, int *rank, int x, int y, int *nets) {
    x = find(root, x);
    y = find(root, y);
    if(x != y) {
        --(*nets);
        if(rank[x] > rank[y])
            root[y] = x;
        else if(rank[x] < rank[y])
            root[x] = y;
        else
            ++rank[root[y] = x];
    }
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
                int x = atoi(token);
                token = strtok(NULL, " ");
                int y = atoi(token);
                unite(root, rank, x, y, &nets);
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
