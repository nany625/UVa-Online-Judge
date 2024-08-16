#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 1000000

int **pos, size[MAX_NUM + 1];

int main() {
    pos = (int**)malloc((MAX_NUM + 1) * sizeof(int*));
    for(int i = 1; i <= MAX_NUM; ++i)
        pos[i] = NULL;
    int m;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%*d %d", &m) == 1) {
        getchar();
        memset(size, 0, sizeof(size));
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int index = 0;
        while(token) {
            int num = atoi(token);
            pos[num] = (int*)realloc(pos[num], (size[num] + 1) * sizeof(int));
            pos[num][size[num]++] = ++index;
            token = strtok(NULL, " ");
        }
        while(m--) {
            int k, v;
            scanf("%d %d", &k, &v);
            printf("%d\n", size[v] >= k ? pos[v][k - 1] : 0);
        }
    }
    free(buffer);
    for(int i = 1; i <= MAX_NUM; ++i)
        free(pos[i]);
    free(pos);
    return 0;
}
