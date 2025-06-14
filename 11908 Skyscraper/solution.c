#include <stdio.h>
#include <stdlib.h>
#define MAXN 30000

typedef struct {
    int A, B, C;
} Advertisement;

Advertisement ad[MAXN];
int dp[MAXN];

int binarySearch(int size, int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(ad[mid].B <= key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int compare(const void *a, const void *b) {
    return ((Advertisement*)a)->B > ((Advertisement*)b)->B;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N;
        scanf("%d", &N);
        for(int j = 0; j < N; ++j) {
            scanf("%d %d %d", &ad[j].A, &ad[j].B, &ad[j].C);
            ad[j].B += ad[j].A;
        }
        qsort(ad, N, sizeof(Advertisement), compare);
        dp[0] = ad[0].C;
        for(int j = 1; j < N; ++j) {
            int pos = binarySearch(j, ad[j].A);
            if(pos == 0)
                dp[j] = dp[j - 1] > ad[j].C ? dp[j - 1] : ad[j].C;
            else
                dp[j] = dp[j - 1] > dp[pos - 1] + ad[j].C ? dp[j - 1] : dp[pos - 1] + ad[j].C;
        }
        printf("Case %d: %d\n", i, dp[N - 1]);
    }
	return 0;
}
