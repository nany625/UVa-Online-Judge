#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int lostCount = 0;

typedef struct {
    int x, y;
} Coordinate;

bool contain(Coordinate *array, int x, int y) {
    for(int i = 0; i < lostCount; ++i) {
        if(array[i].x == x && array[i].y == y)
            return true;
    }
    return false;
}

void append(Coordinate **array, int x, int y) {
    *array = (Coordinate*)realloc(*array, (lostCount + 1) * sizeof(Coordinate));
    (*array)[lostCount].x = x;
    (*array)[lostCount++].y = y;
}
int main() {
    int boundX, boundY;
    scanf("%d %d", &boundX, &boundY);
    Coordinate *lostCoordinates = NULL;
    int x, y;
    char orientation;
    while(scanf("%d %d %c", &x, &y, &orientation) == 3) {
        bool lost = false;
        char instructions[100];
        scanf("%s", instructions);
        for(int i = 0; i < strlen(instructions) && !lost; ++i) {
            if(orientation == 'N') {
                if(instructions[i] == 'L')
                    orientation = 'W';
                else if(instructions[i] == 'R')
                    orientation = 'E';
                else if(instructions[i] == 'F') {
                    if(y < boundY)
                        ++y;
                    else if(!contain(lostCoordinates, x, y)) {
                        append(&lostCoordinates, x, y);
                        lost = true;
                    }
                }
            } else if(orientation == 'E') {
                if(instructions[i] == 'L')
                    orientation = 'N';
                else if(instructions[i] == 'R')
                    orientation = 'S';
                else if(instructions[i] == 'F') {
                    if(x < boundX)
                        ++x;
                    else if(!contain(lostCoordinates, x, y)) {
                        append(&lostCoordinates, x, y);
                        lost = true;
                    }
                }
            } else if(orientation == 'S') {
                if(instructions[i] == 'L')
                    orientation = 'E';
                else if(instructions[i] == 'R')
                    orientation = 'W';
                else if(instructions[i] == 'F') {
                    if(y > 0)
                        --y;
                    else if(!contain(lostCoordinates, x, y)) {
                        append(&lostCoordinates, x, y);
                        lost = true;
                    }
                }
            } else {
                if(instructions[i] == 'L')
                    orientation = 'S';
                else if(instructions[i] == 'R')
                    orientation = 'N';
                else if(instructions[i] == 'F') {
                    if(x > 0)
                        --x;
                    else if(!contain(lostCoordinates, x, y)) {
                        append(&lostCoordinates, x, y);
                        lost = true;
                    }
                }
            }
        }
        printf("%d %d %c%s", x, y, orientation, lost ? " LOST\n" : "\n");
    }
    free(lostCoordinates);
    return 0;
}
