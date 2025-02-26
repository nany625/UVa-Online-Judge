#include <stdio.h>

int min(int a, int b, int c) {
    b = b < a ? b : a;
    return c < b ? c : b;
}

int levenshteinDistance(char *X, char *Y, int m, int n) {
    int dp[n + 1];
    for(int i = 0; i <= n; ++i)
        dp[i] = i;
    for(int i = 1; i <= m; ++i) {
        int prev = dp[0];
        dp[0] = i;
        for(int j = 1; j <= n; ++j) {
            int temp = dp[j];
            if(X[i - 1] == Y[j - 1])
                dp[j] = prev;
            else
                dp[j] = 1 + min(dp[j], dp[j - 1], prev);
            prev = temp;
        }
    }
    return dp[n];
}

int main() {
    int lenX;
    while(scanf("%d", &lenX) == 1) {
        char x[lenX + 1];
        scanf("%s", x);
        int lenY;
        scanf("%d", &lenY);
        char y[lenY + 1];
        scanf("%s", y);
        printf("%d\n", levenshteinDistance(x, y, lenX, lenY));
    }
    return 0;
}
