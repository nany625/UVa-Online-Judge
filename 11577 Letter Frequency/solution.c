#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int cases;
    scanf("%d ", &cases);
    char buffer[201];
    while(cases--) {
        fgets(buffer, sizeof(buffer), stdin);
        int count[26] = {}, len = strlen(buffer);
        for(int i = 0; i < len; ++i) {
            if(isupper(buffer[i]))
                ++count[buffer[i] - 'A'];
            else if(islower(buffer[i]))
                ++count[buffer[i] - 'a'];
        }
        int max = 0;
        for(int i = 0; i < 26; ++i)
            max = max > count[i] ? max : count[i];
        for(int i = 0; i < 26; ++i) {
            if(max == count[i])
                putchar('a' + i);
        }
        putchar('\n');
    }
    return 0;
}
