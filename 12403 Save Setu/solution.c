#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    char operation[7];
    int total = 0;
    while(T--) {
        scanf("%s", operation);
        if(strcmp(operation, "donate") == 0) {
            int K;
            scanf("%d", &K);
            total += K;
        } else
            printf("%d\n", total);
    }
	return 0;
}
