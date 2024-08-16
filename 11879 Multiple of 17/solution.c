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
            int subtract = 5 * (n[len - 1] - '0');
            if(n[len - 2] - '0' >= subtract % 10)
                n[len - 2] -= subtract % 10;
            else {
                n[len - 2] += 10 - subtract % 10;
                --n[len - 3];
            }
            if(n[len - 3] - '0' >= subtract / 10)
                n[len - 3] -= subtract / 10;
            else {
                n[len - 3] += 10 - subtract / 10;
                --n[len - 4];
            }
            int i = len - 4;
            while(n[i] - '0' < 0) {
                n[i] += 10;
                --n[i--];
            }
            int dividend = 0;
            for(i = 0; i < len - 1; ++i)
                dividend = (10 * dividend + n[i] - '0') % 17;
            printf("%d\n", dividend == 0);
        }
    }
    return 0;
}
