#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ans[] = {76, 16, 56, 96, 36};

int main() {
    int T;
    scanf("%d", &T);
    char n[1002];
    while(T--) {
        scanf("%s", n);
        if(n[0] == '0')
            puts("1");
        else if(strlen(n) == 1 && n[0] == '1')
            puts("66");
        else
            printf("%d\n", ans[(n[strlen(n) - 1] - '0') % 5]);
    }
	return 0;
}
