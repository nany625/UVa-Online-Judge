#include <stdio.h>
#include <string.h>

char ans[][3] = {"76", "16", "56", "96", "36"};

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
            puts(ans[(n[strlen(n) - 1] - '0') % 5]);
    }
	return 0;
}
