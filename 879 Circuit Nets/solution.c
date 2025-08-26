#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(int *root, int x) {
    return root[x] == x ? x : (root[x] = find(root, root[x]));
}

int main() {
    int cases;
    scanf("%d", &cases);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(cases--) {
        int N;
        scanf("%d", &N);
        getchar();
        int root[N + 1];
        for(int i = 1; i <= N; ++i)
            root[i] = i;
        int nets = N;
        while(getline(&buffer, &bufsize, stdin) != -1 && buffer[0] != '\n') {
            char *token = strtok(buffer, " ");
            while(token) {
                int root1 = find(root, atoi(token));
                token = strtok(NULL, " ");
                int root2 = find(root, atoi(token));
                if(root1 != root2) {
                    root[root2] = root1;
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
