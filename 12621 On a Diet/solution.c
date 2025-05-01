#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SUM 498

int subsetSum(int *array, int size, int target) {
    bool subsetSum[MAX_SUM + 1];
    subsetSum[0] = true;
    memset(subsetSum + 1, 0, MAX_SUM * sizeof(bool));
    for(int i = 0; i < size; ++i) {
        for(int j = MAX_SUM; j >= array[i]; --j)
            subsetSum[j] |= subsetSum[j - array[i]];
    }
    for(int i = target; i <= MAX_SUM; ++i) {
        if(subsetSum[i])
            return i;
    }
    return -1;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, p;
        scanf("%d %d", &n, &p);
        n /= 10;
        int calories[p];
        for(int i = 0; i < p; ++i) {
            scanf("%d", &calories[i]);
            calories[i] /= 10;
        }
        int ans = subsetSum(calories, p, n);
        if(ans == -1)
            puts("NO SOLUTION");
        else
            printf("%d0\n", ans);
    }
	return 0;
}
