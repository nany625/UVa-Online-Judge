#include <stdio.h>
#include <stdbool.h>

int main() {
    char ch;
    bool odd = true;
    while((ch = getchar()) != EOF) {
        if(ch == '"' && odd) {
            printf("``");
            odd = false;
        } else if(ch == '"' && !odd) {
            printf("''");
            odd = true;
        } else
            putchar(ch);
    }
    return 0;
}
