#include <stdio.h>

int dRow[] = {1, -1, 0, 0}, dCol[] = {0, 0, 1, -1};
char grid[100][101];

void dfs(int row, int col, int N) {
    grid[row][col] = '.';
    for(int i = 0; i < 4; ++i) {
        int newRow = row + dRow[i], newCol = col + dCol[i];
        if(newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && (grid[newRow][newCol] == 'x' || grid[newRow][newCol] == '@'))
            dfs(newRow, newCol, N);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N;
        scanf("%d", &N);
        for(int j = 0; j < N; ++j)
            scanf("%s", grid[j]);
        int count = 0;
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                if(grid[j][k] == 'x') {
                    ++count;
                    dfs(j, k, N);
                }
            }
        }
        printf("Case %d: %d\n", i, count);
    }
	return 0;
}
