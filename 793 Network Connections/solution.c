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
    if(rootX != rootY) {
        if(rank[rootX] > rank[rootY])
            root[rootY] = rootX;
        else if(rank[rootX] < rank[rootY])
            root[rootX] = rootY;
        else
            ++rank[root[rootY] = rootX];
    }
}

int main() {
    int cases;
    scanf("%d", &cases);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(cases--) {
        int computers;
        scanf("%d ", &computers);
        int root[computers + 1], rank[computers + 1];
        init(root, rank, computers);
	    int succ = 0, unsucc = 0;
	    while(getline(&buffer, &bufsize, stdin) != -1 && buffer[0] != '\n') {
	        char *token = strtok(buffer, " ");
	        char command = token[0];
	        token = strtok(NULL, " ");
            int computeri = atoi(token);
            token = strtok(NULL, " ");
            int computerj = atoi(token);
            int rootI = find(root, computeri);
			int rootJ = find(root, computerj);
			if(command == 'c')
			    unite(root, rank, rootI, rootJ);
			else if(command == 'q')
			    root[rootI] == root[rootJ] ? ++succ : ++unsucc;
	    }
        printf("%d,%d\n", succ, unsucc);
        if(cases)
            putchar('\n');
    }
    free(buffer);
	return 0;
}
