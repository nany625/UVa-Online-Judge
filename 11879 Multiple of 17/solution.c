#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char n[102];
    while(scanf("%s", n) && n[0] != '0') {
        int len = strlen(n);
        if(len < 10) {
            int num = atoi(n);
            printf("%d\n", (num / 10 - num % 10 * 5) % 17 == 0);
        } else {
            int dividend = 0;
            for(int i = 0; i < len; ++i)
                dividend = (10 * dividend + n[i] - '0') % 17;
            printf("%d\n", dividend == 0);
        }
    }
    return 0;
}
