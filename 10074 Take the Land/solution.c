#include <stdio.h>
#include <stdbool.h>

int matrix[100][100];

bool allZero(int row, int startCol, int endCol) {
    for(int i = startCol; i < endCol; ++i) {
        if(matrix[row][i] != 0)
            return false;
    }
    return true;
}

int main() {
    int M, N;
    while(scanf("%d %d", &M, &N) && M != 0) {
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j)
                scanf("%d", &matrix[i][j]);
        }
        int max = 0;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(matrix[i][j] == 0) {
                    int endCol = j + 1;
                    while(endCol < N && matrix[i][endCol] == 0)
                        ++endCol;
                    int startRow = i - 1;
                    while(startRow >= 0 && allZero(startRow, j, endCol))
                        --startRow;
                    int endRow = i + 1;
                    while(endRow < M && allZero(endRow, j, endCol))
                        ++endRow;
                    int temp = (endRow - startRow - 1) * (endCol - j);
                    max = max > temp ? max : temp;
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
