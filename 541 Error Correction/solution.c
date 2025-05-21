#include <stdio.h>

int main() {
	int n;
	while(scanf("%d", &n) && n != 0) {
		int matrix[n + 1][n + 1];
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				scanf("%d", &matrix[i][j]);
		}
		for(int i = 0; i < n; ++i) {
			matrix[i][n] = 0;
			for(int j = 0; j < n; ++j)
				matrix[i][n] += matrix[i][j];
		}
		for(int i = 0; i < n; ++i) {
			matrix[n][i] = 0;
			for(int j = 0; j < n; ++j)
				matrix[n][i] += matrix[j][i];
		}
		int count1 = 0, row;
		for(int i = 0; i < n; ++i) {
			if(matrix[i][n] & 1) {
				++count1;
				row = i;
			}
		}
		int count2 = 0, col;
		for(int i = 0; i < n; ++i) {
			if(matrix[n][i] & 1) {
				++count2;
				col = i;
			}
		}
		if(count1 + count2 == 0)
			puts("OK");
		else if(count1 == 1 && count2 == 1)
			printf("Change bit (%d,%d)\n", row + 1, col + 1);
		else
			puts("Corrupt");
	}
	return 0;
}
