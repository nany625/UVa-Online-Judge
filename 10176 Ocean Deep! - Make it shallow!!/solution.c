#include <stdio.h>
#include <string.h>

int main() {
    char buffer[101];
    int remainder = 0;
    while(scanf("%s", buffer) == 1) {
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
    return 0;
}
