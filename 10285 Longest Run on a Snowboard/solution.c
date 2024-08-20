#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dRow[] = {1, 0, 0, -1}, dCol[] = {0, 1, -1, 0};
short height[100][100], memo[100][100];

int dfs(int row, int rowLimit, int col, int colLimit) {
    if(memo[row][col] != 0)
        return memo[row][col];
    int maxLength = 1;
    for(int i = 0; i < 4; ++i) {
        int newRow = row + dRow[i], newCol = col + dCol[i];
        if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit && height[newRow][newCol] < height[row][col]) {
            int temp = 1 + dfs(newRow, rowLimit, newCol, colLimit);
            maxLength = maxLength > temp ? maxLength : temp;
        }
    }
    return memo[row][col] = maxLength;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        char *name = NULL;
        int R, C;
        scanf("%ms %d %d", &name, &R, &C);
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j)
                scanf("%hd", &height[i][j]);
        }
        memset(memo, 0, sizeof(memo));
        int max = 1;
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                int length = dfs(i, R, j, C);
                max = max > length ? max : length;
            }
        }
        printf("%s: %d\n", name, max);
        free(name);
    }
    return 0;
}
