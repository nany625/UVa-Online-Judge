#include <stdio.h>
#include <stdlib.h>

void dfs(char **map, int row, int rowLimit, int col, int colLimit, char region) {
    if(map[row][col] == region) {
        map[row][col] = ' ';
        if(row - 1 >= 0)
            dfs(map, row - 1, rowLimit, col, colLimit, region);
        if(col - 1 >= 0)
            dfs(map, row, rowLimit, col - 1, colLimit, region);
        else
            dfs(map, row, rowLimit, colLimit - 1, colLimit, region);
        if(row + 1 < rowLimit)
            dfs(map, row + 1, rowLimit, col, colLimit, region);
        if(col + 1 < colLimit)
            dfs(map, row, rowLimit, col + 1, colLimit, region);
        else
            dfs(map, row, rowLimit, 0, colLimit, region);
    }
}

void capture(char **map, int row, int rowLimit, int col, int colLimit, char region, int *area) {
    if(map[row][col] == region) {
        map[row][col] = ' ';
        ++(*area);
        if(row - 1 >= 0)
            capture(map, row - 1, rowLimit, col, colLimit, region, area);
        if(col - 1 >= 0)
            capture(map, row, rowLimit, col - 1, colLimit, region, area);
        else
            capture(map, row, rowLimit, colLimit - 1, colLimit, region, area);
        if(row + 1 < rowLimit)
            capture(map, row + 1, rowLimit, col, colLimit, region, area);
        if(col + 1 < colLimit)
            capture(map, row, rowLimit, col + 1, colLimit, region, area);
        else
            capture(map, row, rowLimit, 0, colLimit, region, area);
    }
}

int main() {
    int M, N;
    while(scanf("%d %d", &M, &N) == 2) {
        char **map = (char**)malloc(M * sizeof(char*));
        for(int i = 0; i < M; ++i) {
            map[i] = (char*)malloc((N + 1) * sizeof(char));
            scanf("%s", map[i]);
        }
        int X, Y;
        scanf("%d %d", &X, &Y);
        char region = map[X][Y];
        dfs(map, X, M, Y, N, region);
        int max = 0;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(map[i][j] == region) {
                    int curr = 0;
                    capture(map, i, M, j, N, region, &curr);
                    max = max > curr ? max : curr;
                }
            }
        }
        printf("%d\n", max);
        for(int i = 0; i < M; ++i)
            free(map[i]);
        free(map);
    }
	return 0;
}
