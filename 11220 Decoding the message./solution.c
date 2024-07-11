#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    getchar();
    for(int i = 1; i <= T; ++i) {
        if(i > 1)
            puts("");
        printf("Case #%d:\n", i);
        char *buffer = NULL;
        size_t bufsize = 0;
        while(getline(&buffer, &bufsize, stdin) != -1 && strcmp(buffer, "\n") != 0) {
            char *token = strtok(buffer, " ");
            int count = 0;
            while(token) {
                if(strlen(token) > count)
                    putchar(token[count++]);
                token = strtok(NULL, " ");
            }
            puts("");
        }
        free(buffer);
    }
	return 0;
}
