#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *word = NULL;
    while(scanf("%ms", &word) == 1) {
        int len = strlen(word);
        for(int i = 0; i < len; ++i) {
            switch(word[i]) {
                case 'B':
                case 'F':
                case 'P':
                case 'V':
                    word[i] = '1';
                    break;
                case 'C':
                case 'G':
                case 'J':
                case 'K':
                case 'Q':
                case 'S':
                case 'X':
                case 'Z':
                    word[i] = '2';
                    break;
                case 'D':
                case 'T':
                    word[i] = '3';
                    break;
                case 'L':
                    word[i] = '4';
                    break;
                case 'M':
                case 'N':
                    word[i] = '5';
                    break;
                case 'R':
                    word[i] = '6';
            }
        }
        if(isdigit(word[0]))
            putchar(word[0]);
        for(int i = 1; i < len; ++i) {
            if(isdigit(word[i]) && word[i] != word[i - 1])
                putchar(word[i]);
        }
        puts("");
        free(word);
    }
    return 0;
}
