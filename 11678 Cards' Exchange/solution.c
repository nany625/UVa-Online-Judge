#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int A, B;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%d %d", &A, &B) && A != 0 && B != 0) {
        getchar();
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int *X = NULL, sizeX = 0;
        while(token) {
            int temp = atoi(token);
            if(sizeX == 0 || (sizeX > 0 && temp > X[sizeX - 1])) {
                X = (int*)realloc(X, (sizeX + 1) * sizeof(int));
                X[sizeX++] = temp;
            }
            token = strtok(NULL, " ");
        }
        getline(&buffer, &bufsize, stdin);
        token = strtok(buffer, " ");
        int *Y = NULL, sizeY = 0;
        while(token) {
            int temp = atoi(token);
            if(sizeY == 0 || (sizeY > 0 && temp > Y[sizeY - 1])) {
                Y = (int*)realloc(Y, (sizeY + 1) * sizeof(int));
                Y[sizeY++] = temp;
            }
            token = strtok(NULL, " ");
        }
        int i = 0, j = 0, countX = 0, countY = 0;
        while(i < sizeX && j < sizeY) {
            if(X[i] == Y[j]) {
                ++i;
                ++j;
            } else if(X[i] < Y[j]) {
                ++countX;
                ++i;
            } else {
                ++countY;
                ++j;
            }
        }
        countX += sizeX - i;
        countY += sizeY - j;
        printf("%d\n", countX < countY ? countX : countY);
        free(X);
        free(Y);
    }
    free(buffer);
	return 0;
}
