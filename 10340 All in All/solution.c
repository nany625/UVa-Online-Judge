#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s = NULL, *t = NULL;
    while(scanf("%ms %ms", &s, &t) == 2) {
        int i = 0, j = 0, lens = strlen(s), lent = strlen(t);
        while(j < lent) {
            if(s[i] == t[j])
                ++i;
            if(i == lens) {
                puts("Yes");
                break;
            }
            ++j;
        }
        if(i < lens)
            puts("No");
        free(s);
        free(t);
        s = t = NULL;
    }
    return 0;
}
