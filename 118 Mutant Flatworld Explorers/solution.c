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
    char orientation, instructions[100];
    while(scanf("%d %d %c", &x, &y, &orientation) == 3) {
        bool lost = false;
        scanf("%s", instructions);
        int len = strlen(instructions);
        for(int i = 0; i < len && !lost; ++i) {
            switch(orientation) {
                case 'N':
                    switch(instructions[i]) {
                        case 'L':
                            orientation = 'W';
                            break;
                        case 'R':
                            orientation = 'E';
                            break;
                        case 'F':
                            if(y < boundY)
                                ++y;
                            else if(!contain(lostCoordinates, x, y)) {
                                append(&lostCoordinates, x, y);
                                lost = true;
                            }
                    }
                    break;
                case 'E':
                    switch(instructions[i]) {
                        case 'L':
                            orientation = 'N';
                            break;
                        case 'R':
                            orientation = 'S';
                            break;
                        case 'F':
                            if(x < boundX)
                                ++x;
                            else if(!contain(lostCoordinates, x, y)) {
                                append(&lostCoordinates, x, y);
                                lost = true;
                            }
                    }
                    break;
                case 'S':
                    switch(instructions[i]) {
                        case 'L':
                            orientation = 'E';
                            break;
                        case 'R':
                            orientation = 'W';
                            break;
                        case 'F':
                            if(y > 0)
                                --y;
                            else if(!contain(lostCoordinates, x, y)) {
                                append(&lostCoordinates, x, y);
                                lost = true;
                            }
                    }
                    break;
                case 'W':
                    switch(instructions[i]) {
                        case 'L':
                            orientation = 'S';
                            break;
                        case 'R':
                            orientation = 'N';
                            break;
                        case 'F':
                            if(x > 0)
                                --x;
                            else if(!contain(lostCoordinates, x, y)) {
                                append(&lostCoordinates, x, y);
                                lost = true;
                            }
                    }
            }
        }
        printf("%d %d %c%s\n", x, y, orientation, lost ? " LOST" : "");
    }
    free(lostCoordinates);
    return 0;
}
