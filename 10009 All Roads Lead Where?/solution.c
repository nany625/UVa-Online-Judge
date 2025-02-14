#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int parent, child;
} Edge;

char cityName[26], city1[9], city2[9];

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int m, n;
        scanf("%d %d ", &m, &n);
        int cityID[26];
        for(int i = 0; i < 26; ++i)
            cityID[i] = -1;
        Edge edges[m];
        int id = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%s", city1);
            if(cityID[city1[0] - 'A'] == -1) {
                cityID[city1[0] - 'A'] = id;
                cityName[id++] = city1[0];
            }
            scanf("%s", city2);
            if(cityID[city2[0] - 'A'] == -1) {
                cityID[city2[0] - 'A'] = id;
                cityName[id++] = city2[0];
            }
            edges[i] = (Edge){cityID[city1[0] - 'A'], cityID[city2[0] - 'A']};
        }
        int **conn = (int**)malloc(id * sizeof(int*)), connSize[id];
        for(int i = 0; i < id; ++i) {
            conn[i] = NULL;
            connSize[i] = 0;
        }
        for(int i = 0; i < m; ++i) {
            conn[edges[i].parent] = (int*)realloc(conn[edges[i].parent], (connSize[edges[i].parent] + 1) * sizeof(int));
            conn[edges[i].parent][connSize[edges[i].parent]++] = edges[i].child;
            conn[edges[i].child] = (int*)realloc(conn[edges[i].child], (connSize[edges[i].child] + 1) * sizeof(int));
            conn[edges[i].child][connSize[edges[i].child]++] = edges[i].parent;
        }
        while(n--) {
            scanf("%s", city1);
            int start = cityID[city1[0] - 'A'];
            scanf("%s", city2);
            int end = cityID[city2[0] - 'A'];
            int prev[id];
            bool visited[id];
            memset(visited, 0, sizeof(visited));
            visited[prev[start] = start] = true;
            int **bfs = (int**)malloc(sizeof(int*)), currSize = 1, step = 1;
            bfs[0] = (int*)malloc(sizeof(int));
            bfs[0][0] = start;
            while(!visited[end]) {
                bfs = (int**)realloc(bfs, (step + 1) * sizeof(int*));
                bfs[step] = NULL;
                int nextSize = 0;
                for(int i = 0; i < currSize; ++i) {
                    for(int j = 0; j < connSize[bfs[step - 1][i]]; ++j) {
                        if(!visited[conn[bfs[step - 1][i]][j]]) {
                            bfs[step] = (int*)realloc(bfs[step], (nextSize + 1) * sizeof(int));
                            bfs[step][nextSize++] = conn[bfs[step - 1][i]][j];
                            visited[conn[bfs[step - 1][i]][j]] = true;
                            prev[conn[bfs[step - 1][i]][j]] = bfs[step - 1][i];
                        }
                    }
                }
                currSize = nextSize;
                ++step;
            }
            int route[step - 1], i = 0;
            while(end != start) {
                route[i++] = end;
                end = prev[end];
            }
            putchar(cityName[start]);
            while(i--)
                putchar(cityName[route[i]]);
            putchar('\n');
            for(i = 0; i < step; ++i)
                free(bfs[i]);
            free(bfs);
        }
        if(cases)
            putchar('\n');
        for(int i = 0; i < id; ++i)
            free(conn[i]);
        free(conn);
    }
    return 0;
}
