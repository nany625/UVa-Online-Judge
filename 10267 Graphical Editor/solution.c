#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dRow[] = {1, 0, 0, -1}, dCol[] = {0, 1, -1, 0};
char table[250][251];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void fill(int row1, int row2, int col1, int col2, char C) {
    for(int i = row1; i <= row2; ++i)
        memset(table[i] + col1, C, (col2 - col1 + 1) * sizeof(char));
}

void dfs(int row, int rowLimit, int col, int colLimit, char R, char C) {
    if(C != R) {
        table[row][col] = C;
        for(int i = 0; i < 4; ++i) {
            int newRow = row + dRow[i], newCol = col + dCol[i];
            if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit && table[newRow][newCol] == R)
                dfs(newRow, rowLimit, newCol, colLimit, R, C);
        }
    }
}

int main() {
	char command, C, *buffer = NULL;
	size_t bufsize = 0;
	int M, N, X, X1, X2, Y, Y1, Y2;
	while(scanf("%c", &command) && command != 'X') {
	    switch(command) {
    		case 'I':
    			scanf("%d %d", &M, &N);
    			fill(0, N - 1, 0, M - 1, 'O');
    			break;
    		case 'C':
    			fill(0, N - 1, 0, M - 1, 'O');
    			break;
    		case 'L':
    			scanf("%d %d %c", &X, &Y, &C);
    			table[Y - 1][X - 1] = C;
    			break;
    		case 'V':
    			scanf("%d %d %d %c", &X, &Y1, &Y2, &C);
    			if(Y1 > Y2)
    			    swap(&Y1, &Y2);
    			for(int i = Y1 - 1; i <= Y2 - 1; ++i)
    				table[i][X - 1] = C;
    			break;
    		case 'H':
    			scanf("%d %d %d %c", &X1, &X2, &Y, &C);
    			if(X1 > X2)
    			    swap(&X1, &X2);
    			memset(table[Y - 1] + X1 - 1, C, X2 - X1 + 1);
    		    break;
    		case 'K':
    			scanf("%d %d %d %d %c", &X1, &Y1, &X2, &Y2, &C);
    			fill(Y1 - 1, Y2 - 1, X1 - 1, X2 - 1, C);
    		    break;
    		case 'F':
    			scanf("%d %d %c", &X, &Y, &C);
    			dfs(Y - 1, N, X - 1, M, table[Y - 1][X - 1], C);
    		    break;
    		case 'S':
    			scanf("%ms", &buffer);
    			puts(buffer);
    			for(int i = 0; i < N; ++i)
    			    printf("%.*s\n", M, table[i]);
	    }
	    getline(&buffer, &bufsize, stdin);
		free(buffer);
		buffer = NULL;
	}
	return 0;
}
