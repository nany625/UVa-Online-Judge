#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findRoot(int* root, int child) {
	return root[child] == child ? child : root[child] = findRoot(root, root[child]);
}

int main() {
    int cases;
    scanf("%d", &cases);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(cases--) {
        int computers;
        scanf("%d ", &computers);
        int root[computers + 1];
        for(int i = 1; i <= computers; ++i)
			root[i] = i;
	    int succ = 0, unsucc = 0;
	    while(getline(&buffer, &bufsize, stdin) != -1 && buffer[0] != '\n') {
	        char *token = strtok(buffer, " ");
	        char command = token[0];
	        token = strtok(NULL, " ");
            int computeri = atoi(token);
            token = strtok(NULL, " ");
            int computerj = atoi(token);
            int rootI = findRoot(root, computeri);
			int rootJ = findRoot(root, computerj);
			if(command == 'c')
			    root[rootI] = root[rootJ];
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
