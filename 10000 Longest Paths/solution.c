#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 100

short **links, linksCount[MAX_NUM + 1];
bool visited[MAX_NUM + 1];

int main() {
    links = (short**)malloc((MAX_NUM + 1) * sizeof(short*));
    for(int i = 1; i <= MAX_NUM; ++i)
        links[i] = NULL;
    int cases = 0, n;
    while(scanf("%d", &n) && n != 0) {
        int s;
        scanf("%d", &s);
        memset(linksCount, 0, sizeof(linksCount));
        int p, q;
        while(scanf("%d %d", &p, &q) && p != 0) {
            links[p] = (short*)realloc(links[p], (linksCount[p] + 1) * sizeof(short));
            links[p][linksCount[p]++] = q;
        }
        int curr[n - 1], next[n - 1], length = 0, currSize = 1;
        curr[0] = s;
        while(true) {
            memset(visited, 0, sizeof(visited));
            int nextSize = 0;
            for(int i = 0; i < currSize; ++i) {
                for(int j = 0; j < linksCount[curr[i]]; ++j) {
                    if(!visited[links[curr[i]][j]])
                        visited[next[nextSize++] = links[curr[i]][j]] = true;
                }
            }
            if(nextSize == 0)
                break;
            for(int i = 0; i < nextSize; ++i)
                curr[i] = next[i];
            ++length;
            currSize = nextSize;
        }
        int finish = curr[0];
        for(int i = 1; i < currSize; ++i)
            finish = finish < curr[i] ? finish : curr[i];
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++cases, s, length, finish);
    }
    for(int i = 1; i <= MAX_NUM; ++i)
        free(links[i]);
    free(links);
	return 0;
}
