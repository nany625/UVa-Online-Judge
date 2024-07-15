#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char expression[31];
    while(scanf("%s", expression) == 1) {
        int len = strlen(expression);
        for(int i = 0; i < len; ++i) {
            if(isupper(expression[i])) {
                if(expression[i] <= 'C')
                    putchar('2');
                else if(expression[i] <= 'F')
                    putchar('3');
                else if(expression[i] <= 'I')
                    putchar('4');
                else if(expression[i] <= 'L')
                    putchar('5');
                else if(expression[i] <= 'O')
                    putchar('6');
                else if(expression[i] <= 'S')
                    putchar('7');
                else if(expression[i] <= 'V')
                    putchar('8');
                else
                    putchar('9');
            } else
                putchar(expression[i]);
        }
        puts("");
    }
    return 0;
}
