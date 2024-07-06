#include <stdio.h>

int dRow[] = {0, 1, 0, -1, 1, 1, -1, -1}, dCol[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main() {
	int x = 0, n, m;
	while(scanf("%d %d", &n, &m) && (n != 0 || m != 0)) {
	    if(x >= 1)
	        puts("");
	    printf("Field #%d:\n", ++x);
	    char field[n][m + 1];
	    for(int i = 0; i < n; ++i)
	        scanf("%s", field[i]);
	    for(int i = 0; i < n; ++i) {
	        for(int j = 0; j < m; ++j) {
	            if(field[i][j] == '.') {
	                field[i][j] = '0';
	                for(int dir = 0; dir < 8; ++dir) {
	                    int newRow = i + dRow[dir], newCol = j + dCol[dir];
	                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && field[newRow][newCol] == '*')
	                        ++field[i][j];
	                }
	            }
	        }
	    }
	    for(int i = 0; i < n; ++i)
	        printf("%s\n", field[i]);
	}
	return 0;
}
