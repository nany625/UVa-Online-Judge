#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char ch, keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    int len = strlen(keyboard);
    while((ch = getchar()) != EOF) {
        if(ch == ' ' || ch == '\n')
            putchar(ch);
        else {
            if(isupper(ch))
                tolower(ch);
            for(int i = 0; i < len; ++i) {
                if(ch == keyboard[i]) {
                    putchar(keyboard[i - 2]);
                    break;
                }
            }
        }
    }
    return 0;
}
