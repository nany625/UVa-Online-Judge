#include <stdio.h>
#include <string.h>

int GCD(int i, int j) {
    return j == 0 ? i : GCD(j, i % j);
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        char S1[31], S2[31];
        scanf("%s %s", S1, S2);
        int num1 = 0, num2 = 0, len = strlen(S1);
        for(int i = 0; i < len; ++i)
            num1 = 2 * num1 + S1[i] - '0';
        len = strlen(S2);
        for(int i = 0; i < len; ++i)
            num2 = 2 * num2 + S2[i] - '0';
        printf("Pair #%d: %s!\n", i, GCD(num1, num2) > 1 ? "All you need is love" : "Love is not all you need");
    }
    return 0;
}
