#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d ", &T);
    char decode[82];
    while(T--) {
        while(fgets(decode, sizeof(decode), stdin) && decode[0] != '\n') {
            int len = strlen(decode);
            for(int i = 0; i < len; ++i) {
                switch(decode[i]) {
                    case '0':
                        putchar('O');
                        break;
                    case '1':
                        putchar('I');
                        break;
                    case '2':
                        putchar('Z');
                        break;
                    case '3':
                        putchar('E');
                        break;
                    case '4':
                        putchar('A');
                        break;
                    case '5':
                        putchar('S');
                        break;
                    case '6':
                        putchar('G');
                        break;
                    case '7':
                        putchar('T');
                        break;
                    case '8':
                        putchar('B');
                        break;
                    case '9':
                        putchar('P');
                        break;
                    default:
                        putchar(decode[i]);
                }
            }
        }
        if(T)
            putchar('\n');
    }
    return 0;
}
