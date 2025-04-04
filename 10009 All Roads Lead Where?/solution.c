#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int parent, child;
} Edge;

int curr[25], next[25];
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
            visited[curr[0] = prev[start] = start] = true;
            int currSize = 1, step = 0;
            while(!visited[end]) {
                int nextSize = 0;
                for(int i = 0; i < currSize; ++i) {
                    for(int j = 0; j < connSize[curr[i]]; ++j) {
                        if(!visited[conn[curr[i]][j]]) {
                            visited[next[nextSize++] = conn[curr[i]][j]] = true;
                            prev[conn[curr[i]][j]] = curr[i];
                        }
                    }
                }
                for(int i = 0; i < nextSize; ++i)
                    curr[i] = next[i];
                currSize = nextSize;
                ++step;
            }
            int route[step], i = 0;
            while(end != start) {
                route[i++] = end;
                end = prev[end];
            }
            putchar(cityName[start]);
            while(i--)
                putchar(cityName[route[i]]);
            putchar('\n');
        }
        if(cases)
            putchar('\n');
        for(int i = 0; i < id; ++i)
            free(conn[i]);
        free(conn);
    }
    return 0;
}
