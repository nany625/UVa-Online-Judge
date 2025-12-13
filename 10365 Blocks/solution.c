#include <stdio.h>

int ans[1001];

int main() {
    for(int i = 1; i <= 10; ++i) {
        for(int j = i; j <= 32; ++j) {
            for(int k = j; k <= 1000; ++k) {
                if(i * j * k > 1000)
                    break;
                int temp = (i * j + j * k + i * k) << 1;
                if(ans[i * j * k] == 0)
                    ans[i * j * k] = temp;
                else
                    ans[i * j * k] = temp < ans[i * j * k] ? temp : ans[i * j * k];
            }
        }
    }
    int C;
    scanf("%d", &C);
    while(C--) {
        int N;
        scanf("%d", &N);
        printf("%d\n", ans[N]);
    }
	return 0;
}
