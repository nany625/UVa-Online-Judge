#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *a = NULL, *b = NULL;
    size_t bufsizea = 0, bufsizeb = 0;
    while(getline(&a, &bufsizea, stdin) != -1 && getline(&b, &bufsizeb, stdin) != -1) {
        short frequencya[26] = {}, output[26] = {};
        int len = strlen(a);
        for(int i = 0; i < len; ++i)
            ++frequencya[a[i] - 'a'];
        len = strlen(b);
        for(int i = 0; i < len; ++i) {
            if(output[b[i] - 'a'] < frequencya[b[i] - 'a'])
                ++output[b[i] - 'a'];
        }
        for(int i = 0; i < 26; ++i) {
            while(output[i]--)
                putchar('a' + i);
        }
        puts("");
    }
    free(a);
    free(b);
    return 0;
}
