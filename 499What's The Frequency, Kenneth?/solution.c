#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[93];
    while(fgets(text, sizeof(text), stdin)) {
        char frequency[52] = {}, max = 0;
        int len = strlen(text);
        for(int i = 0; i < len; ++i) {
            if(isupper(text[i]))
                max = max > ++frequency[text[i] - 'A'] ? max : frequency[text[i] - 'A'];
            else if(islower(text[i]))
                max = max > ++frequency[text[i] - 'a' + 26] ? max : frequency[text[i] - 'a' + 26];
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
    return 0;
}
