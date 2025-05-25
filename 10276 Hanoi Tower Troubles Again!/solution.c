#include <stdio.h>

int ans[50] = {1};

int main() {
    for(int n = 1; n < 50; ++n)
        ans[n] = ans[n - 1] + (((n >> 1) + 1) << 1);
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        scanf("%d", &N);
        printf("%d\n", ans[N - 1]);
    }
	return 0;
}
