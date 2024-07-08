#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = NULL;
    int remainder = 0;
    while(scanf("%ms", &buffer) == 1) {
        int len = strlen(buffer);
        for(int i = 0; i < len; ++i) {
            if(buffer[i] != '#')
                remainder = (2 * remainder + buffer[i] -'0') % 131071;
            else {
                puts(remainder == 0 ? "YES" : "NO");
                remainder = 0;
            }
        }
        free(buffer);
        buffer = NULL;
    }
    return 0;
}
