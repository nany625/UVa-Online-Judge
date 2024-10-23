#include <stdio.h>
#include <stdlib.h>

int directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void update(char **today, char **tomorrow, int i, int j, int r, int c) {
	char curr = tomorrow[i][j] = today[i][j], winner = (curr == 'R') ? 'S' : (curr == 'S') ? 'P' : 'R', loser = (curr == 'R') ? 'P' : (curr == 'S') ? 'R' : 'S';
    for(int k = 0; k < 4; ++k) {
    	int ni = i + directions[k][0], nj = j + directions[k][1];
    	if(ni >= 0 && ni < r && nj >= 0 && nj < c) {
    		if(today[ni][nj] == winner)
    			tomorrow[ni][nj] = curr;
    		else if(today[ni][nj] == loser)
    			tomorrow[i][j] = loser;
    	}
    }
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int r, c, n;
		scanf("%d %d %d", &r, &c, &n);
		char **grid0 = (char**)malloc(r * sizeof(char*)), **grid1 = (char**)malloc(r * sizeof(char*));
		for(int i = 0; i < r; ++i) {
			scanf("%ms", &grid0[i]);
			grid1[i] = (char*)calloc(c + 1, sizeof(char));
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < r; ++j) {
				for(int k = 0; k < c; ++k) {
					if(i & 1)
						update(grid0, grid1, j, k, r, c);
					else
						update(grid1, grid0, j, k, r, c);
				}
			}
		}
		for(int i = 0; i < r; ++i) {
		    puts(n & 1 ? grid1[i] : grid0[i]);
		    free(grid0[i]);
		    free(grid1[i]);
    	}
    	free(grid0);
    	free(grid1);
    	if(t)
            putchar('\n');
	}
	return 0;
}
