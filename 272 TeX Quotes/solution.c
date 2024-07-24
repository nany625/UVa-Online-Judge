#include <stdio.h>
#include <stdbool.h>

int main() {
    char ch;
    bool odd = true;
    while((ch = getchar()) != EOF) {
        if(ch == '"' && odd) {
            fputs("``", stdout);
            odd = false;
        } else if(ch == '"' && !odd) {
            fputs("''", stdout);
            odd = true;
        } else
            putchar(ch);
    }
    return 0;
}
