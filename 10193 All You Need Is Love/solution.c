#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int i, int j) {
    return j == 0 ? i : GCD(j, i % j);
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        char *S1 = NULL, *S2 = NULL;
        scanf("%ms %ms", &S1, &S2);
        int num1 = 0, num2 = 0, len = strlen(S1);
        for(int j = 0; j < len; ++j)
            num1 = 2 * num1 + S1[j] - '0';
        len = strlen(S2);
        for(int j = 0; j < len; ++j)
            num2 = 2 * num2 + S2[j] - '0';
        printf("Pair #%d: %s!\n", i, GCD(num1, num2) > 1 ? "All you need is love" : "Love is not all you need");
        free(S1);
        free(S2);
    }
    return 0;
}
