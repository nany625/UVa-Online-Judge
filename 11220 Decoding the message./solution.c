#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d ", &T);
    char *buffer = NULL;
    size_t bufsize = 0;
    for(int i = 1; i <= T; ++i) {
        if(i > 1)
            putchar('\n');
        printf("Case #%d:\n", i);
        while(getline(&buffer, &bufsize, stdin) != -1 && buffer[0] != '\n') {
            char *token = strtok(buffer, " ");
            int count = 0;
            while(token) {
                if(strlen(token) > count)
                    putchar(token[count++]);
                token = strtok(NULL, " ");
            }
            putchar('\n');
        }
    }
    free(buffer);
	return 0;
}
