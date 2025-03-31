#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NUM 100

short **links, linksCount[MAX_NUM + 1];
bool visited[MAX_NUM + 1];

int main() {
    links = (short**)malloc((MAX_NUM + 1) * sizeof(short*));
    for(int i = 1; i <= MAX_NUM; ++i)
        links[i] = NULL;
    int cases = 0, a, b;
    while(scanf("%d %d", &a, &b) && a != 0) {
        memset(linksCount, 0, sizeof(linksCount));
        memset(visited, 0, sizeof(visited));
        links[a] = (short*)realloc(links[a], (linksCount[a] + 1) * sizeof(short));
        links[a][linksCount[a]++] = b;
        int *nodes = (int*)malloc(2 * sizeof(int)), nodesCount = 2;
        visited[nodes[0] = a] = visited[nodes[1] = b] = true;
        while(scanf("%d %d", &a, &b) && a != 0) {
            links[a] = (short*)realloc(links[a], (linksCount[a] + 1) * sizeof(short));
            links[a][linksCount[a]++] = b;
            if(!visited[a]) {
                nodes = (int*)realloc(nodes, (nodesCount + 1) * sizeof(int));
                visited[nodes[nodesCount++] = a] = true;
            }
            if(!visited[b]) {
                nodes = (int*)realloc(nodes, (nodesCount + 1) * sizeof(int));
                visited[nodes[nodesCount++] = b] = true;
            }
        }
        int path[nodesCount][nodesCount - 1], sum = 0;
        for(int i = 0; i < nodesCount; ++i) {
            memset(visited, 0, sizeof(visited));
            visited[path[0][0] = nodes[i]] = true;
            int currSize = 1, length = 1;
            while(currSize > 0) {
                int nextSize = 0;
                for(int j = 0; j < currSize; ++j) {
                    for(int k = 0; k < linksCount[path[length - 1][j]]; ++k) {
                        if(!visited[links[path[length - 1][j]][k]])
                            visited[path[length][nextSize++] = links[path[length - 1][j]][k]] = true;
                    }
                }
                sum += length++ * (currSize = nextSize);
            }
        }
        printf("Case %d: average length between pages = %.3lf clicks\n", ++cases, (double)sum / nodesCount / (nodesCount - 1));
        free(nodes);
    }
    for(int i = 1; i <= MAX_NUM; ++i)
        free(links[i]);
    free(links);
	return 0;
}
