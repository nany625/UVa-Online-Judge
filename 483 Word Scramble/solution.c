#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char *buffer = NULL;
    size_t bufsize = 0;
    while(getline(&buffer, &bufsize, stdin) != -1) {
        buffer[strcspn(buffer, "\n")] = '\0';
        char *token = strtok(buffer, " ");
        bool firstToken = true;
        while(token) {
            if(!firstToken)
                putchar(' ');
            int len = strlen(token);
            for(int i = len - 1; i >= 0; --i)
                putchar(token[i]);
            firstToken = false;
            token = strtok(NULL, " ");
        }
        putchar('\n');
    }
    free(buffer);
	return 0;
}
