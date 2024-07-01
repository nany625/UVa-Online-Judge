#include <stdio.h>
#include <string.h>

char table[250][251];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void fill(int row1, int row2, int col1, int col2, char C) {
    for(int i = row1; i <= row2; ++i)
        memset(table[i] + col1, C, col2 - col1 + 1);
}

void dfs(int row, int rowLimit, int col, int colLimit, char R, char C) {
    if(C != R) {
        table[row][col] = C;
        if(row + 1 < rowLimit && table[row + 1][col] == R)
            dfs(row + 1, rowLimit, col, colLimit, R, C);
        if(col + 1 < colLimit && table[row][col + 1] == R)
            dfs(row, rowLimit, col + 1, colLimit, R, C);
        if(row - 1 >= 0 && table[row - 1][col] == R)
            dfs(row - 1, rowLimit, col, colLimit, R, C);
        if(col - 1 >= 0 && table[row][col - 1] == R)
            dfs(row, rowLimit, col - 1, colLimit, R, C);
    }
}

int main() {
	char command, C, Name[101], ignore[101];
	int M, N, X, X1, X2, Y, Y1, Y2;
	while(scanf("%c", &command) && command != 'X') {
		if(command == 'I') {
			scanf("%d %d", &M, &N);
			fill(0, N - 1, 0, M - 1, 'O');
		} else if(command == 'C')
			fill(0, N - 1, 0, M - 1, 'O');
		else if(command == 'L') {
			scanf("%d %d %c", &X, &Y, &C);
			table[Y - 1][X - 1] = C;
		} else if(command == 'V') {
			scanf("%d %d %d %c", &X, &Y1, &Y2, &C);
			if(Y1 > Y2)
			    swap(&Y1, &Y2);
			for(int i = Y1 - 1; i <= Y2 - 1; ++i)
				table[i][X - 1] = C;
		} else if(command == 'H') {
			scanf("%d %d %d %c", &X1, &X2, &Y, &C);
			if(X1 > X2)
			    swap(&X1, &X2);
			memset(table[Y - 1] + X1 - 1, C, X2 - X1 + 1);
		} else if(command == 'K') {
			scanf("%d %d %d %d %c", &X1, &Y1, &X2, &Y2, &C);
			fill(Y1 - 1, Y2 - 1, X1 - 1, X2 - 1, C);
		} else if(command == 'F') {
			scanf("%d %d %c", &X, &Y, &C);
			dfs(Y - 1, N, X - 1, M, table[Y - 1][X - 1], C);
		} else if(command == 'S') {
			scanf("%s", Name);
			printf("%s\n", Name);
			for(int i = 0; i < N; ++i)
			    printf("%.*s\n", M, table[i]);
		}
		fgets(ignore, sizeof(ignore), stdin);
	}
	return 0;
}
