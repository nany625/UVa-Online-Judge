#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int dRow[] = {1, 1, 1, 0, 0, -1, -1, -1}, dCol[] = {1, 0, -1, 1, -1, 1, 0, -1};
char grid[99][100];
bool visited[99][99];

void dfs(int row, int rowLimit, int col, int colLimit, int *area) {
    ++(*area);
    visited[row][col] = true;
    for(int i = 0; i < 8; ++i) {
        int newRow = row + dRow[i], newCol = col + dCol[i];
        if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit && !visited[newRow][newCol] && grid[newRow][newCol] == grid[row][col])
            dfs(newRow, rowLimit, newCol, colLimit, area);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    getchar();
    int n = 0;
    char buffer[101];
    while(T--) {
        while(fgets(buffer, sizeof(buffer), stdin) && buffer[0] != '\n') {
            if(isupper(buffer[0])) {
                buffer[strcspn(buffer, "\n")] = '\0';
                strcpy(grid[n++], buffer);
            } else {
                char *token = strtok(buffer, " ");
                int i = atoi(token) - 1;
                token = strtok(NULL, " ");
                int j = atoi(token) - 1, m = strlen(grid[0]), area = 0;
                memset(visited, 0, sizeof(visited));
                dfs(i, n, j, m, &area);
                printf("%d\n", area);
            }
        }
        n = 0;
        if(T)
            putchar('\n');
    }
	return 0;
}
