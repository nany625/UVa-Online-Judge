#include <stdio.h>

int dp[1000], denomination[10][10], size[10];

int main() {
	int S;
	while(scanf("%d", &S) && S != 0) {
	    int N;
	    scanf("%d", &N);
	    for(int i = 0; i < N; ++i) {
            scanf("%d", &size[i]);
            for(int j = 0; j < size[i]; ++j)
                scanf("%d", &denomination[i][j]);
	    }
	    int max = -1, ans = -1;
	    for(int i = 0; i < N; ++i) {
            for(int j = 1; j <= S * denomination[i][size[i] - 1]; ++j)
                dp[j] = S + 1;
            dp[0] = 0;
            for(int j = 0; j < size[i]; ++j) {
                for(int k = denomination[i][j]; k <= S * denomination[i][size[i] - 1]; ++k)
                    dp[k] = dp[k] < dp[k - denomination[i][j]] + 1 ? dp[k] : dp[k - denomination[i][j]] + 1;
            }
            int temp = 1;
            while(temp <= S * denomination[i][size[i] - 1] && dp[temp] <= S)
                ++temp;
            if(max < temp - 1) {
                max = temp - 1;
                ans = i;
            } else if(max == temp - 1) {
                if(size[i] < size[ans])
                    ans = i;
                else if(size[i] == size[ans]) {
                    int j = 0;
                    while(denomination[i][size[i] - 1 - j] == denomination[ans][size[ans] - 1 - j])
                        ++j;
                    ans = denomination[i][size[i] - 1 - j] < denomination[ans][size[ans] - 1 - j] ? i : ans;
                }
            }
	    }
	    printf("max coverage = %3d :", max);
	    for(int i = 0; i < size[ans]; ++i)
            printf("%3d", denomination[ans][i]);
        putchar('\n');
	}
	return 0;
}
