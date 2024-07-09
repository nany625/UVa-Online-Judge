#include <stdio.h>
#include <ctype.h>

int main() {
    char ch, keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    while((ch = getchar()) != EOF) {
        if(ch == ' ' || ch == '\n')
            putchar(ch);
        else {
            if(isupper(ch))
                tolower(ch);
            int i = 2;
            while(ch != keyboard[i])
                ++i;
            putchar(keyboard[i - 2]);
        }
    }
    return 0;
}
