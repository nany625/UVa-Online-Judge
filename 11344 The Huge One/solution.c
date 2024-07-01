#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char M[1002];
    int N;
    scanf("%d", &N);
    while(N--) {
        scanf("%s", M);
        int len = strlen(M), S;
        scanf("%d", &S);
        bool wonderful = true;
        while(S--) {
            short divisor;
            scanf("%hd", &divisor);
            if(wonderful) {
                int remainder = 0;
                for(int i = 0; i < len; ++i) {
                    int dividend = 10 * remainder + M[i] - '0';
                    remainder = dividend % divisor;
                }
                if(remainder != 0)
                    wonderful = false;
            }
        }
        printf("%s - %s\n", M, wonderful ? "Wonderful." : "Simple.");
    }
    return 0;
}
