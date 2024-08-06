#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int main() {
    int cases = 0, n;
    while(scanf("%d", &n) && n != 0) {
        printf("Case %d:\n", ++cases);
        int set[n];
        for(int i = 0; i < n; ++i)
            scanf("%d", &set[i]);
        qsort(set, n, sizeof(int), compare);
        int m;
        scanf("%d", &m);
        while(m--) {
            int query;
            scanf("%d", &query);
            int ans = set[0] + set[1];
            for(int i = 0; i < n - 1 && set[i] <= query; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    int sum = set[i] + set[j];
                    ans = abs(query - ans) < abs(query - sum) ? ans : sum;
                    if(sum > query)
                        break;
                }
            }
            printf("Closest sum to %d is %d.\n", query, ans);
        }
    }
	return 0;
}
