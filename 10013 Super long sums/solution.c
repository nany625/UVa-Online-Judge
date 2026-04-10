#include <stdio.h>
#define MAX_LEN 1000000

char ans[MAX_LEN + 2];

int main() {
    int N;
    scanf("%d", &N);
    char digits[5];
    while(N--) {
        int M;
        scanf("%d ", &M);
        ans[M + 1] = '\0';
        for(int i = 1; i <= M; ++i) {
            fgets(digits, sizeof(digits), stdin);
            ans[i] = digits[0] + digits[2] - '0';
        }
        ans[0] = '0';
        do {
            ans[M - 1] += (ans[M] - '0') / 10;
            ans[M] = (ans[M] - '0') % 10 + '0';
        } while(--M);
        if(ans[0] == '1')
            putchar('1');
        puts(ans + 1);
		if(N)
			putchar('\n');
    }
    return 0;
}
