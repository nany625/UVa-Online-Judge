#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 1000000

int main() {
    int **index = (int**)malloc((MAX_NUM + 1) * sizeof(int*)), size[MAX_NUM + 1];
    for(int i = 1; i <= MAX_NUM; ++i)
        index[i] = NULL;
    int m;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%*d %d", &m) == 1) {
        getchar();
        memset(size, 0, sizeof(size));
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int pos = 0;
        while(token) {
            int num = atoi(token);
            index[num] = (int*)realloc(index[num], (size[num] + 1) * sizeof(int));
            index[num][size[num]++] = ++pos;
            token = strtok(NULL, " ");
        }
        while(m--) {
            int k, v;
            scanf("%d %d", &k, &v);
            printf("%d\n", size[v] >= k ? index[v][k - 1] : 0);
        }
    }
    free(buffer);
    for(int i = 1; i <= MAX_NUM; ++i)
        free(index[i]);
    free(index);
    return 0;
}
