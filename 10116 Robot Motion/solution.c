#include <stdio.h>
#include <string.h>

char grid[10][11];
int steps[10][10];

int main() {
    int rows, cols, currCol;
    while(scanf("%d %d %d", &rows, &cols, &currCol) && rows != 0) {
        for(int i = 0; i < rows; ++i)
            scanf("%s", grid[i]);
        bool exit = false;
        int currRow = 0, step = 0;
        --currCol;
        memset(steps, -1, sizeof(steps));
        steps[currRow][currCol] = 0;
        while(true) {
            ++step;
            switch(grid[currRow][currCol]) {
                case 'N':
                    --currRow;
                    break;
                case 'E':
                    ++currCol;
                    break;
                case 'S':
                    ++currRow;
                    break;
                case 'W':
                    --currCol;
            }
            if(currRow == -1 || currRow == rows || currCol == -1 || currCol == cols) {
                printf("%d step(s) to exit\n", step);
                break;
            }
            if(steps[currRow][currCol] != -1) {
                printf("%d step(s) before a loop of %d step(s)\n", steps[currRow][currCol], step - steps[currRow][currCol]);
                break;
            }
            steps[currRow][currCol] = step;
        }
    }
	return 0;
}
