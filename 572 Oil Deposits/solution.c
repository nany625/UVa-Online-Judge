#include <stdio.h>

int dRow[] = {0, 1, 0, -1, 1, 1, -1, -1}, dCol[] = {1, 0, -1, 0, 1, -1, 1, -1};
char grid[100][101];

void dfs(int row, int rowLimit, int col, int colLimit) {
    if(grid[row][col] == '@') {
        grid[row][col] = '*';
        for(int i = 0; i < 8; ++i) {
            int newRow = row + dRow[i], newCol = col + dCol[i];
            if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit)
                dfs(newRow, rowLimit, newCol, colLimit);
        }
    }
}

int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) && m != 0 && n != 0) {
        for(int i = 0; i < m; ++i)
            scanf("%s", grid[i]);
        int count = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '@') {
                    ++count;
                    dfs(i, m, j, n);
                }
            }
        }
        printf("%d\n", count);
    }
	return 0;
}
