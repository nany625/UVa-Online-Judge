#include <stdio.h>

int dRow[] = {1, 0, 0, -1}, dCol[] = {0, 1, -1, 0};
short height[100][100];

void dfs(int row, int rowLimit, int col, int colLimit, int *max, int curr) {
    for(int i = 0; i < 4; ++i) {
        int newRow = row + dRow[i], newCol = col + dCol[i];
        if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit && height[newRow][newCol] < height[row][col])
            dfs(newRow, rowLimit, newCol, colLimit, max, curr + 1);
    }
    *max = *max > curr ? *max : curr;
}

int main() {
    int N;
    scanf("%d", &N);
    while(N--) {
        char *name = NULL;
        int R, C;
        scanf("%ms %d %d", &name, &R, &C);
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j)
                scanf("%hd", &height[i][j]);
        }
        int max = 1;
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                int curr = 1;
                dfs(i, R, j, C, &max, curr);
            }
        }
        printf("%s: %d\n", name, max);
    }
	return 0;
}
