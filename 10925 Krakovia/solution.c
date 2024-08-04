// 尚未通過UVa
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
            int len = strlen(V), maxLen = findMax(digits, len);
            sum = (char*)realloc(sum, (maxLen + 2) * sizeof(char));
            for(int i = digits; i <= maxLen; ++i)
                sum[i] = '0';
            sum[maxLen + 1] = '\0';
            for(int i = 0; i < len; ++i) {
                sum[i + 1] += (sum[i] + V[len - 1 - i] - 2 * '0') / 10;
                sum[i] = (sum[i] + V[len - 1 - i] - 2 * '0') % 10 + '0';
            }
            digits = maxLen + (sum[maxLen] == '1');
        }
        printf("Bill #%d costs ", ++cases);
        for(int i = digits - 1; i >= 0; --i)
            putchar(sum[i]);
        fputs(": each friend should pay ", stdout);
        int dividend = 0;
        bool leadingZero = true;
        for(int i = digits - 1; i >= 0; --i) {
            dividend = 10 * dividend + sum[i] - '0';
            char quotient = dividend / F + '0';
            leadingZero = leadingZero && (quotient == '0');
            if(!leadingZero)
                putchar(quotient);
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
