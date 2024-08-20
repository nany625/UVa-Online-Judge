#include <stdio.h>

int dRow[] = {1, 0, 0, -1}, dCol[] = {0, 1, -1, 0};
char map[20][21];

void dfs(int row, int rowLimit, int col, int colLimit, char region) {
    if(map[row][col] == region) {
        map[row][col] = ' ';
        for(int i = 0; i < 4; ++i) {
            int newRow = row + dRow[i], newCol = col + dCol[i];
            if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit)
                dfs(newRow, rowLimit, newCol, colLimit, region);
            else if(newCol == -1)
                dfs(newRow, rowLimit, colLimit - 1, colLimit, region);
            else if(newCol == colLimit)
                dfs(newRow, rowLimit, 0, colLimit, region);
        }
    }
}

void capture(int row, int rowLimit, int col, int colLimit, char region, int *area) {
    if(map[row][col] == region) {
        map[row][col] = ' ';
        ++(*area);
        for(int i = 0; i < 4; ++i) {
            int newRow = row + dRow[i], newCol = col + dCol[i];
            if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit)
                capture(newRow, rowLimit, newCol, colLimit, region, area);
            else if(newCol == -1)
                capture(newRow, rowLimit, colLimit - 1, colLimit, region, area);
            else if(newCol == colLimit)
                capture(newRow, rowLimit, 0, colLimit, region, area);
        }
    }
}

int main() {
    int M, N;
    while(scanf("%d %d", &M, &N) == 2) {
        for(int i = 0; i < M; ++i)
            scanf("%s", map[i]);
        int X, Y;
        scanf("%d %d", &X, &Y);
        char region = map[X][Y];
        dfs(X, M, Y, N, region);
        int max = 0;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(map[i][j] == region) {
                    int area = 0;
                    capture(i, M, j, N, region, &area);
                    max = max > area ? max : area;
                }
            }
        }
        printf("%d\n", max);
    }
	return 0;
}
