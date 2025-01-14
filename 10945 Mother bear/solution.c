#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *buffer = NULL;
    size_t bufsize = 0;
    while(getline(&buffer, &bufsize, stdin) != -1 && strncmp(buffer, "DONE", 4) != 0) {
        int i = 0, j = strlen(buffer) - 2;
        while(i < j) {
            while(i < j && !isalpha(buffer[i]))
                ++i;
            while(i < j && !isalpha(buffer[j]))
                --j;
            if(tolower(buffer[i]) != tolower(buffer[j]))
                break;
            ++i;
            --j;
        }
        puts(i >= j ? "You won't be eaten!" : "Uh oh..");
    }
    free(buffer);
	return 0;
}
