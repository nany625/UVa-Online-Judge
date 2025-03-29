#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSubsetSum(int *array, int size, int sum) {
    bool subsetSum[sum + 1];
    subsetSum[0] = true;
    memset(subsetSum + 1, 0, sum * sizeof(bool));
    for(int i = 0; i < size && !subsetSum[sum]; ++i) {
        for(int j = sum; j >= array[i] && !subsetSum[sum]; --j)
            subsetSum[j] |= subsetSum[j - array[i]];
    }
    return subsetSum[sum];
}

int main() {
    int cases;
    scanf("%d ", &cases);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(cases--) {
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int *weights = NULL, size = 0, sum = 0;
        while(token) {
            weights = (int*)realloc(weights, (size + 1) * sizeof(int));
            sum += weights[size++] = atoi(token);
            token = strtok(NULL, " ");
        }
        if(sum & 1)
            puts("NO");
        else
            puts(isSubsetSum(weights, size, sum >> 1) ? "YES" : "NO");
        free(weights);
    }
    free(buffer);
	return 0;
}
