#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int findMax(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int cases = 0, N, F;
    char V[22];
    while(scanf("%d %d", &N, &F) && N != 0 && F != 0) {
        char *sum = NULL;
        int digits = 0;
        while(N--) {
            scanf("%s", V);
            int len = strlen(V);
            sum = (char*)realloc(sum, (findMax(digits, len) + 1) * sizeof(char));
            for(int j = digits; j <= findMax(digits, len); ++j)
                sum[j] = '0';
            for(int j = 0; j < len; ++j) {
                sum[j + 1] += (sum[j] + V[len - 1 - j] - 2 * '0') / 10;
                sum[j] = (sum[j] + V[len - 1 - j] - 2 * '0') % 10 + '0';
            }
            digits = findMax(digits, len) + (sum[findMax(digits, len)] == '1');
        }
        printf("Bill #%d costs ", ++cases);
        for(int i = digits - 1; i >= 0; --i)
            putchar(sum[i]);
        fputs(": each friend should pay ", stdout);
        int dividend = 0;
        bool leadingZero = true;
        for(int i = digits - 1; i >= 0; --i) {
            dividend = 10 * dividend + sum[i] - '0';
            leadingZero = leadingZero && (dividend / F == 0);
            if(!leadingZero)
                putchar(dividend / F + '0');
            dividend %= F;
        }
        if(leadingZero)
            putchar('0');
        putchar('\n');
        putchar('\n');
        free(sum);
    }
	return 0;
}
