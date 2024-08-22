#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int dRow[] = {2, 2, 1, 1, -1, -1, -2, -2}, dCol[] = {1, -1, 2, -2, 2, -2, 1, -1};

typedef struct {
    int row, col;
} Square;

int main() {
    char buffer[7];
    while(fgets(buffer, sizeof(buffer), stdin)) {
        if(strncmp(buffer, buffer + 3, 2) == 0) {
            printf("To get from %.2s to %.2s takes 0 knight moves.\n", buffer, buffer + 3);
            continue;
        }
        Square **squares = (Square**)malloc(sizeof(Square*));
        squares[0] = (Square*)malloc(sizeof(Square));
        squares[0][0].row = buffer[1] - '1';
        squares[0][0].col = buffer[0] - 'a';
        int endRow = buffer[4] - '1', endCol = buffer[3] - 'a', currSize = 1, move = 1;
        bool visited[8][8] = {}, found = false;
        visited[squares[0][0].row][squares[0][0].col] = true;
        while(!found) {
            squares = (Square**)realloc(squares, (move + 1) * sizeof(Square*));
            squares[move] = NULL;
            int nextSize = 0;
            for(int i = 0; i < currSize && !found; ++i) {
                for(int j = 0; j < 8 && !found; ++j) {
                    int newRow = squares[move - 1][i].row + dRow[j];
                    int newCol = squares[move - 1][i].col + dCol[j];
                    if(newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                        if(newRow == endRow && newCol == endCol) {
                            printf("To get from %c%c to %c%c takes %d knight moves.\n", buffer[0], buffer[1], buffer[3], buffer[4], move);
                            found = true;
                        } else if(!visited[newRow][newCol]) {
                            squares[move] = (Square*)realloc(squares[move], (nextSize + 1) * sizeof(Square));
                            squares[move][nextSize].row = newRow;
                            squares[move][nextSize++].col = newCol;
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
            currSize = nextSize;
            ++move;
        }
        for(int i = 0; i < move; ++i)
            free(squares[i]);
        free(squares);
    }
    return 0;
}
