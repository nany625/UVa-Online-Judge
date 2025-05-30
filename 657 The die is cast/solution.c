#include <stdio.h>
#include <stdbool.h>

int dRow[] = {1, -1, 0, 0}, dCol[] = {0, 0, 1, -1}, count[6];
char grid[50][51];

void dfsDots(int row, int col, int h, int w) {
    grid[row][col] = '*';
    for(int i = 0; i < 4; ++i) {
        int newRow = row + dRow[i], newCol = col + dCol[i];
        if(newRow >= 0 && newRow < h && newCol >= 0 && newCol < w) {
            if(grid[newRow][newCol] == 'X')
                dfsDots(newRow, newCol, h, w);
        }
    }
}

void dfs(int row, int col, int h, int w, int *dots) {
    if(grid[row][col] == 'X') {
        ++(*dots);
        dfsDots(row, col, h, w);
        dfs(row, col, h, w, dots);
    }
    grid[row][col] = '.';
    for(int i = 0; i < 4; ++i) {
        int newRow = row + dRow[i], newCol = col + dCol[i];
        if(newRow >= 0 && newRow < h && newCol >= 0 && newCol < w) {
            if(grid[newRow][newCol] == '*')
                dfs(newRow, newCol, h, w, dots);
            else if(grid[newRow][newCol] == 'X') {
                ++(*dots);
                dfsDots(newRow, newCol, h, w);
                dfs(newRow, newCol, h, w, dots);
            }
        }
    }
}

int main() {
    int Throws = 0, w, h;
    while(scanf("%d %d", &w, &h) && w != 0) {
        printf("Throw %d\n", ++Throws);
        for(int i = 0; i < h; ++i)
            scanf("%s", grid[i]);
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(grid[i][j] != '.') {
                    int dots = 0;
                    dfs(i, j, h, w, &dots);
                    ++count[dots - 1];
                }
            }
        }
        bool firstDice = true;
        for(int i = 0; i < 6; ++i) {
            if(count[i] > 0) {
                do {
                    if(!firstDice)
                        putchar(' ');
                    printf("%d", i + 1);
                    firstDice = false;
                } while(--count[i]);
            }
        }
        puts("\n");
    }
	return 0;
}
