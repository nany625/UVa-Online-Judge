#include <stdio.h>
#define MAXN 50000

int ans[MAXN + 1] = {0, 1};

void computePhi() {
    for(int n = 2; n <= MAXN; ++n) {
        if(ans[n] == n) {
            for(int i = n; i <= MAXN; i += n)
                ans[i] -= ans[i] / n;
        }
        ans[n] = (ans[n] << 1) + ans[n - 1];
    }
}

int main() {
    for(int n = 2; n <= MAXN; ++n)
        ans[n] = n;
    computePhi();
    int N;
    while(scanf("%d", &N) && N != 0)
        printf("%d\n", ans[N]);
	return 0;
}
