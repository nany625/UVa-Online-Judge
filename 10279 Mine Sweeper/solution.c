#include <stdio.h>
#include <stdbool.h>

int dRow[] = {0, 1, 0, -1, 1, 1, -1, -1}, dCol[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main() {
    int games;
    scanf("%d", &games);
    while(games--) {
        int n;
        scanf("%d", &n);
        char mines[n][n + 1], touch[n][n + 1];
        for(int i = 0; i < n; ++i)
            scanf("%s", mines[i]);
        for(int i = 0; i < n; ++i)
            scanf("%s", touch[i]);
        bool boom = false;
        for(int i = 0; i < n; ++i) {
	        for(int j = 0; j < n; ++j) {
	            if(touch[i][j] == 'x') {
	                if(mines[i][j] == '*')
	                    boom = true;
	                else {
    	                touch[i][j] = '0';
    	                for(int dir = 0; dir < 8; ++dir) {
    	                    int newRow = i + dRow[dir], newCol = j + dCol[dir];
    	                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && mines[newRow][newCol] == '*')
    	                        ++touch[i][j];
    	                }
	                }
	            }
	        }
	    }
	    if(boom) {
	        for(int i = 0; i < n; ++i) {
    	        for(int j = 0; j < n; ++j) {
    	            if(mines[i][j] == '*')
    	                touch[i][j] = '*';
    	        }
	        }
	    }
	    for(int i = 0; i < n; ++i)
	        printf("%s\n", touch[i]);
	    if(games)
            putchar('\n');
    }
    return 0;
}
