#include <stdio.h>
#include <string.h>

int dRow[] = {1, 0, 0, -1}, dCol[] = {0, 1, -1, 0};
char grid[99][100];

void dfs(int row, int rowLimit, int col, int colLimit, int *area) {
    if(grid[row][col] == '0') {
        grid[row][col] = '1';
        ++(*area);
        for(int i = 0; i < 4; ++i) {
            int newRow = row + dRow[i], newCol = col + dCol[i];
            if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit)
                dfs(newRow, rowLimit, newCol, colLimit, area);
        }
    }
}

int main() {
    int M;
    scanf("%d", &M);
    char buffer[101];
    while(M--) {
        int i, j;
        scanf("%d %d ", &i, &j);
        int rows = 0;
        while(fgets(buffer, sizeof(buffer), stdin) && buffer[0] != '\n') {
            buffer[strcspn(buffer, "\n")] = '\0';
            strcpy(grid[rows++], buffer);
        }
        int cols = strlen(grid[0]), area = 0;
        dfs(i - 1, rows, j - 1, cols, &area);
        printf("%d\n", area);
        if(M)
            putchar('\n');
    }
	return 0;
}
