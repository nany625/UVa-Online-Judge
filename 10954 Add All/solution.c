#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int main() {
    int N;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%d ", &N) && N != 0) {
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int nums[N];
        for(int i = 0; i < N; ++i) {
            nums[i] = atoi(token);
            token = strtok(NULL, " ");
        }
        qsort(nums, N, sizeof(int), compare);
        long cost = 0;
        for(int i = 0; i < N - 1; ++i) {
            int temp = nums[i] + nums[i + 1];
            cost += temp;
            int j = i + 1;
            while(j < N - 1 && nums[j + 1] < temp) {
                nums[j] = nums[j + 1];
                ++j;
            }
            nums[j] = temp;
        }
        printf("%ld\n", cost);
    }
    free(buffer);
	return 0;
}
