#include <stdio.h>
#include <string.h>

int main() {
    char a[1002], b[1002];
    while(fgets(a, sizeof(a), stdin) && fgets(b, sizeof(b), stdin)) {
        short frequencya[26] = {}, frequencyb[26] = {};
        int len = strlen(a);
        for(int i = 0; i < len; ++i)
            ++frequencya[a[i] - 'a'];
        len = strlen(b);
        for(int i = 0; i < len; ++i)
            ++frequencyb[b[i] - 'a'];
        for(int i = 0; i < 26; ++i) {
            if(frequencya[i] > 0 && frequencyb[i] > 0) {
                short min = frequencya[i] < frequencyb[i] ? frequencya[i] : frequencyb[i];
                while(min--)
                    putchar('a' + i);
            }
        }
        puts("");
    }
    return 0;
}
