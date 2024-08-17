#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int horsedRow[] = {2, 2, 1, 1, -1, -1, -2, -2}, horsedCol[] = {1, -1, 2, -2, 2, -2, 1, -1};
int kingdRow[] = {1, 1, 1, -1, -1, -1, 0, 0}, kingdCol[] = {1, 0, -1, 1, 0, -1, 1, -1};

typedef struct {
    int row, col;
} Coordinate;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int M, N;
        scanf("%d %d", &M, &N);
        char forest[M][N + 1];
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
        Coordinate **trip = (Coordinate**)malloc(sizeof(Coordinate*));
        trip[0] = (Coordinate*)malloc(sizeof(Coordinate));
        trip[0][0].row = kingRow;
        trip[0][0].col = kingCol;
        bool safe = false;
        int currSize = 1, length = 1;
        while(currSize > 0 && !safe) {
            trip = (Coordinate**)realloc(trip, (length + 1) * sizeof(Coordinate*));
            trip[length] = NULL;
            int nextSize = 0;
            for(int i = 0; i < currSize && !safe; ++i) {
                for(int j = 0; j < 8 && !safe; ++j) {
                    int newRow = trip[length - 1][i].row + kingdRow[j];
                    int newCol = trip[length - 1][i].col + kingdCol[j];
                    if(newRow >= 0 && newRow < M && newCol >= 0 && newCol < N) {
                        if(forest[newRow][newCol] == 'B') {
                            printf("Minimal possible length of a trip is %d\n", length);
                            safe = true;
                        } else if(forest[newRow][newCol] == '.') {
                            trip[length] = (Coordinate*)realloc(trip[length], (nextSize + 1) * sizeof(Coordinate));
                            trip[length][nextSize].row = newRow;
                            trip[length][nextSize++].col = newCol;
                            forest[newRow][newCol] = 'z';
                        }
                    }
                }
            }
            currSize = nextSize;
            ++length;
        }
        if(!safe)
            puts("King Peter, you can't go now!");
        for(int i = 0; i < length; ++i)
            free(trip[i]);
        free(trip);
    }
    return 0;
}
