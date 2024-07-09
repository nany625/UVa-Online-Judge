#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int remainder = 0;
    while((ch = getchar()) != EOF) {
        if(ch != '#') {
            if(isdigit(ch))
                remainder = (2 * remainder + ch -'0') % 131071;
        }
        else {
            puts(remainder == 0 ? "YES" : "NO");
            remainder = 0;
        }
    }
    return 0;
}
