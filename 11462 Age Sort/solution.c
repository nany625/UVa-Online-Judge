#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int age[100];

int main() {
    int n;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%d", &n) && n != 0) {
        getchar();
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        while(token) {
            ++age[atoi(token)];
            token = strtok(NULL, " ");
        }
        bool firstNum = true;
        for(int i = 0; i < 100; ++i) {
            if(age[i] > 0) {
                do {
                    if(!firstNum)
                        putchar(' ');
                    printf("%d", i);
                    firstNum = false;
                } while(--age[i]);
            }
        }
        putchar('\n');
    }
    free(buffer);
    return 0;
}
