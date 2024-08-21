#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);
    while(N--) {
        char *M = NULL;
        scanf("%ms", &M);
        int len = strlen(M), S;
        scanf("%d", &S);
        bool wonderful = true;
        while(S--) {
            short divisor;
            scanf("%hd", &divisor);
            if(wonderful) {
                int dividend = 0;
                for(int i = 0; i < len; ++i)
                    dividend = (10 * dividend + M[i] - '0') % divisor;
                wonderful = dividend == 0;
            }
        }
        printf("%s - %s.\n", M, wonderful ? "Wonderful" : "Simple");
        free(M);
    }
    return 0;
}
