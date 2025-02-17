#include <stdio.h>
#include <string.h>

typedef struct {
    int x, y;
} Coordinate;

Coordinate turtles[10001];
char grid[60][61], dir[3];

int main() {
    int N, M, T, K;
    while(scanf("%d %d %d %d", &N, &M, &T, &K) == 4) {
        memset(grid, ' ', sizeof(grid));
        while(T--) {
            int id;
            scanf("%d", &id);
            scanf("%d %d", &turtles[id].x, &turtles[id].y);
            grid[turtles[id].x][turtles[id].y] = '*';
        }
        while(K--) {
            int id;
            scanf("%d %s", &id, dir);
            if(strcmp(dir, "N") == 0) {
                if(turtles[id].x - 1 >= 0 && grid[turtles[id].x - 1][turtles[id].y] != '*') {
                    grid[turtles[id].x][turtles[id].y] = ' ';
                    grid[--turtles[id].x][turtles[id].y] = '*';
                }
            } else if(strcmp(dir, "S") == 0) {
                if(turtles[id].x + 1 < N && grid[turtles[id].x + 1][turtles[id].y] != '*') {
                    grid[turtles[id].x][turtles[id].y] = ' ';
                    grid[++turtles[id].x][turtles[id].y] = '*';
                }
            } else if(strcmp(dir, "E") == 0) {
                if(turtles[id].y + 1 < M && grid[turtles[id].x][turtles[id].y + 1] != '*') {
                    grid[turtles[id].x][turtles[id].y] = ' ';
                    grid[turtles[id].x][++turtles[id].y] = '*';
                }
            } else if(strcmp(dir, "W") == 0) {
                if(turtles[id].y - 1 >= 0 && grid[turtles[id].x][turtles[id].y - 1] != '*') {
                    grid[turtles[id].x][turtles[id].y] = ' ';
                    grid[turtles[id].x][--turtles[id].y] = '*';
                }
            } else if(strcmp(dir, "NE") == 0) {
                if(turtles[id].x - 1 >= 0 && turtles[id].y + 1 < M && grid[turtles[id].x - 1][turtles[id].y + 1] != '*') {
                    grid[turtles[id].x][turtles[id].y] = ' ';
                    grid[--turtles[id].x][++turtles[id].y] = '*';
                }
            } else if(strcmp(dir, "NW") == 0) {
                if(turtles[id].x - 1 >= 0 && turtles[id].y - 1 >= 0 && grid[turtles[id].x - 1][turtles[id].y - 1] != '*') {
                    grid[turtles[id].x][turtles[id].y] = ' ';
                    grid[--turtles[id].x][--turtles[id].y] = '*';
                }
            } else if(strcmp(dir, "SE") == 0) {
                if(turtles[id].x + 1 < N && turtles[id].y + 1 < M && grid[turtles[id].x + 1][turtles[id].y + 1] != '*') {
                    grid[turtles[id].x][turtles[id].y] = ' ';
                    grid[++turtles[id].x][++turtles[id].y] = '*';
                }
            } else {
                if(turtles[id].x + 1 < N && turtles[id].y - 1 >= 0 && grid[turtles[id].x + 1][turtles[id].y - 1] != '*') {
                    grid[turtles[id].x][turtles[id].y] = ' ';
                    grid[++turtles[id].x][--turtles[id].y] = '*';
                }
            }
        }
        for(int i = 0; i < N; ++i) {
            int j = M - 1;
            while(j >= 0 && grid[i][j] != '*')
                --j;
            printf("%.*s\n", j + 1, grid[i]);
        }
        putchar('\n');
    }
	return 0;
}
