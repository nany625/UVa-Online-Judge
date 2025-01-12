#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char toLower(char ch) {
    return isupper(ch) ? ch + 32 : ch;
}

int main() {
    char *buffer = NULL;
    size_t bufsize = 0;
    while(getline(&buffer, &bufsize, stdin) != -1) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if(strcmp(buffer, "DONE") == 0)
            break;
        int i = 0, j = strlen(buffer) - 1;
        while(i < j) {
            while(i < j && !isalpha(buffer[i]))
                ++i;
            while(i < j && !isalpha(buffer[j]))
                --j;
            if(toLower(buffer[i]) != toLower(buffer[j]))
                break;
            ++i;
            --j;
        }
        puts(i >= j ? "You won't be eaten!" : "Uh oh..");
    }
    free(buffer);
	return 0;
}
