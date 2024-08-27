#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int count[6];

bool lastCase() {
    bool result = true;
    for(int i = 0; i < 6; ++i) {
        scanf("%d", &count[i]);
        result &= count[i] == 0;
    }
    return result;
}

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
    int cases = 0;
    while(!lastCase()) {
        int sum = 0;
        for(int i = 0; i < 6; ++i)
            sum += (i + 1) * count[i];
        if(sum % 2 == 1)
            printf("Collection #%d:\nCan't be divided.\n\n", ++cases);
        else {
            int *marbles = NULL, size = 0;
            for(int i = 0; i < 6; ++i) {
                for(int k = 1; k <= count[i]; k *= 2) {
                    marbles = (int*)realloc(marbles, (size + 1) * sizeof(int));
                    marbles[size++] = (i + 1) * k;
                    count[i] -= k;
                }
                if(count[i] > 0) {
                    marbles = (int*)realloc(marbles, (size + 1) * sizeof(int));
                    marbles[size++] = (i + 1) * count[i];
                }
            }
            printf("Collection #%d:\nCan%s be divided.\n\n", ++cases, isSubsetSum(marbles, size, sum / 2) ? "" : "'t");
        }
    }
	return 0;
}
