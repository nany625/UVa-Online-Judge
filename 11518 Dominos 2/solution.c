#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXN 10000

short**knock, knockCount[MAXN + 1];
bool visited[MAXN + 1];

void dfs(int start, int *count) {
    visited[start] = true;
    ++(*count);
    for(short i = 0; i < knockCount[start]; ++i) {
        if(!visited[knock[start][i]])
            dfs(knock[start][i], count);
    }
}

int main() {
    knock = (short**)malloc((MAXN + 1) * sizeof(short*));
    for(short i = 1; i <= MAXN; ++i)
        knock[i] = NULL;
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        short n, m, l;
        scanf("%hd %hd %hd", &n, &m, &l);
        memset(knockCount, 0, sizeof(knockCount));
        while(m--) {
            short x, y;
            scanf("%hd %hd", &x, &y);
            knock[x] = (short*)realloc(knock[x], (knockCount[x] + 1) * sizeof(short));
            knock[x][knockCount[x]++] = y;
        }
        memset(visited, 0, sizeof(visited));
        int count = 0;
        while(l--) {
            short z;
            scanf("%hd", &z);
            if(!visited[z])
                dfs(z, &count);
        }
        printf("%d\n", count);
    }
    for(short i = 1; i <= MAXN; ++i)
        free(knock[i]);
    free(knock);
	return 0;
}
