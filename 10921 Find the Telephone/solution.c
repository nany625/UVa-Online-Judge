#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    while((ch = getchar()) != EOF) {
        if(isupper(ch)) {
            if(ch <= 'C')
                putchar('2');
            else if(ch <= 'F')
                putchar('3');
            else if(ch <= 'I')
                putchar('4');
            else if(ch <= 'L')
                putchar('5');
            else if(ch <= 'O')
                putchar('6');
            else if(ch <= 'S')
                putchar('7');
            else if(ch <= 'V')
                putchar('8');
            else
                putchar('9');
        } else
            putchar(ch);
    }
    return 0;
}
