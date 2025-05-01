#include <stdio.h>

void findSubset(int *nums, int size, int target, int index, int currentSum, int *min) {
    if(currentSum >= target) {
        *min = *min < currentSum ? *min : currentSum;
        return;
    }
    for(int i = index; i < size; ++i) {
        findSubset(nums, size, target, i + 1, currentSum + nums[i], min);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, p;
        scanf("%d %d", &n, &p);
        int calories[p];
        for(int i = 0; i < p; ++i)
            scanf("%d", &calories[i]);
        int min = 1e9;
        findSubset(calories, p, n, 0, 0, &min);
        if(min == 1e9)
            puts("NO SOLUTION");
        else
            printf("%d\n", min);
    }
	return 0;
}
