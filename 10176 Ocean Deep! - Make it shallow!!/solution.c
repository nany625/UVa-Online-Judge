#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = NULL;
    size_t bufsize = 0;
    int remainder = 0;
    while(getline(&buffer, &bufsize, stdin) != -1) {
        buffer[strcspn(buffer, "\n")] = '\0';
        int len = strlen(buffer);
        for(int i = 0; i < len; ++i) {
            if(buffer[i] != '#')
                remainder = (2 * remainder + buffer[i] -'0') % 131071;
            else {
                puts(remainder == 0 ? "YES" : "NO");
                remainder = 0;
            }
        }
    }
    free(buffer);
    return 0;
}
