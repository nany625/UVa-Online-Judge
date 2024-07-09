#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *buffer = NULL;
    size_t bufsize = 0;
    while(getline(&buffer, &bufsize, stdin) != -1) {
        char frequency[52] = {}, max = 0;
        int len = strlen(buffer);
        for(int i = 0; i < len; ++i) {
            if(isupper(buffer[i]))
                max = max > ++frequency[buffer[i] - 'A'] ? max : frequency[buffer[i] - 'A'];
            else if(islower(buffer[i]))
                max = max > ++frequency[buffer[i] - 'a' + 26] ? max : frequency[buffer[i] - 'a' + 26];
        }
        for(int i = 0; i < 26; ++i) {
            if(max == frequency[i])
                putchar(i + 'A');
        }
        for(int i = 26; i < 52; ++i) {
            if(max == frequency[i])
                putchar(i - 26 + 'a');
        }
        printf(" %d\n",max);
    }
    free(buffer);
    return 0;
}
