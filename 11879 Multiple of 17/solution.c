#include <stdio.h>
#include <string.h>

int main() {
    char n[102];
    while(scanf("%s", n) && n[0] != '0') {
        int len = strlen(n), dividend = 0;
        for(int i = 0; i < len; ++i)
            dividend = (10 * dividend + n[i] - '0') % 17;
        puts(dividend == 0 ? "1" : "0");
    }
    return 0;
}
