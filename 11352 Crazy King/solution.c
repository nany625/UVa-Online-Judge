#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int horsedRow[] = {2, 2, 1, 1, -1, -1, -2, -2}, horsedCol[] = {1, -1, 2, -2, 2, -2, 1, -1};
int kingdRow[] = {1, 1, 1, -1, -1, -1, 0, 0}, kingdCol[] = {1, 0, -1, 1, 0, -1, 1, -1};
char forest[100][101];

typedef struct {
    int row, col;
} Coordinate;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int M, N;
        scanf("%d %d", &M, &N);
        for(int i = 0; i < M; ++i)
            scanf("%s", forest[i]);
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(forest[i][j] == 'Z') {
                    for(int k = 0; k < 8; ++k) {
                        int newRow = i + horsedRow[k], newCol = j + horsedCol[k];
                        if(newRow >= 0 && newRow < M && newCol >= 0 && newCol < N && forest[newRow][newCol] == '.')
                            forest[newRow][newCol] = 'z';
                    }
                }
            }
        }
        int kingRow = 0, kingCol = 0;
        while(forest[kingRow][kingCol] != 'A') {
            ++kingCol;
            if(kingCol == N) {
                ++kingRow;
                kingCol = 0;
            }
        }
        forest[kingRow][kingCol] = 'z';
        Coordinate *curr = (Coordinate*)malloc(sizeof(Coordinate));
        curr[0] = (Coordinate){kingRow, kingCol};
        bool safe = false;
        int currSize = 1, length = 1;
        while(currSize > 0 && !safe) {
            Coordinate *next = NULL;
            int nextSize = 0;
            for(int i = 0; i < currSize && !safe; ++i) {
                for(int j = 0; j < 8 && !safe; ++j) {
                    int newRow = curr[i].row + kingdRow[j];
                    int newCol = curr[i].col + kingdCol[j];
                    if(newRow >= 0 && newRow < M && newCol >= 0 && newCol < N) {
                        if(forest[newRow][newCol] == 'B') {
                            printf("Minimal possible length of a trip is %d\n", length);
                            safe = true;
                        } else if(forest[newRow][newCol] == '.') {
                            next = (Coordinate*)realloc(next, (nextSize + 1) * sizeof(Coordinate));
                            next[nextSize++] = (Coordinate){newRow, newCol};
                            forest[newRow][newCol] = 'z';
                        }
                    }
                }
            }
            curr = (Coordinate*)realloc(curr, (nextSize) * sizeof(Coordinate));
            for(int i = 0; i < nextSize; ++i)
                curr[i] = next[i];
            currSize = nextSize;
            ++length;
            free(next);
        }
        if(!safe)
            puts("King Peter, you can't go now!");
        free(curr);
    }
    return 0;
}
