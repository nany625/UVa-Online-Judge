#include <stdio.h>
#include <string.h>

int main() {
    char a[1002], b[1002];
    while(fgets(a, sizeof(a), stdin) && fgets(b, sizeof(b), stdin)) {
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
    return 0;
}
