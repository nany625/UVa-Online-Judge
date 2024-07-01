#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);
    bool blankLine = false;
    while(N--) {
        if(blankLine)
            puts("");
        int M;
        scanf("%d", &M);
        char *ans = (char*)malloc((M + 2) * sizeof(char));
        ans[M + 1] = '\0';
        int digit1, digit2;
        for(int i = 1; i <= M; ++i) {
            scanf("%d %d", &digit1, &digit2);
            ans[i] = digit1 + digit2 + '0';
        }
        ans[0] = '0';
        do {
            ans[M - 1] += (ans[M] - '0') / 10;
            ans[M] = (ans[M] - '0') % 10 + '0';
        } while(--M);
        if(ans[0] == '1')
            putchar('1');
        printf("%s\n", ans + 1);
        free(ans);
		blankLine = true;
    }
    return 0;
}
