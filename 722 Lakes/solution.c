#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void dfs(char **grid, int row, int rowLimit, int col, int colLimit, int *area) {
    if(grid[row][col] == '0') {
        grid[row][col] = '1';
        ++(*area);
        if(row - 1 >= 0)
            dfs(grid, row - 1, rowLimit, col, colLimit, area);
        if(col - 1 >= 0)
            dfs(grid, row, rowLimit, col - 1, colLimit, area);
        if(row + 1 < rowLimit)
            dfs(grid, row + 1, rowLimit, col, colLimit, area);
        if(col + 1 < colLimit)
            dfs(grid, row, rowLimit, col + 1, colLimit, area);
    }
}

int main() {
    int M;
    scanf("%d", &M);
    char buffer[101];
    bool firstCase = true;
    while(M--) {
        if(!firstCase)
            putchar('\n');
        int i, j;
        scanf("%d %d", &i, &j);
        getchar();
        char **grid = NULL;
        int rows = 0;
        while(fgets(buffer, sizeof(buffer), stdin) && buffer[0] != '\n') {
            buffer[strcspn(buffer, "\n")] = '\0';
            grid = (char**)realloc(grid, (rows + 1) * sizeof(char*));
            grid[rows++] = strdup(buffer);
        }
        int cols = strlen(grid[0]), area = 0;
        dfs(grid, i - 1, rows, j - 1, cols, &area);
        printf("%d\n", area);
        for(i = 0; i < rows; ++i)
            free(grid[i]);
        free(grid);
        firstCase = false;
    }
	return 0;
}
