#include <stdio.h>
#include <string.h>

int main() {
    char s[12], t[89937];
    while(scanf("%s %s", s, t) == 2) {
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
    }
    return 0;
}
