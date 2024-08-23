#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isAsequence(short *array, int size) {
    bool subsetSum[array[size - 1] + 1];
    subsetSum[0] = true;
    memset(subsetSum + 1, 0, array[size - 1] * sizeof(bool));
    for(int i = 0; i < size; ++i) {
        if(subsetSum[array[i]])
            return false;
        for(int j = array[size - 1]; j >= array[i]; --j)
            subsetSum[j] = subsetSum[j] || subsetSum[j - array[i]];
    }
    return true;
}

int main() {
    int cases = 0, D;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%d", &D) == 1) {
        printf("Case #%d:", ++cases);
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        short sequence[D];
        bool sorted = true;
        for(int i = 0; i < D; ++i) {
            printf("% hd", sequence[i] = atoi(token));
            if(i > 0 && sequence[i] < sequence[i - 1])
                sorted = false;
            token = strtok(NULL, " ");
        }
        putchar('\n');
        if(!sorted)
            puts("This is not an A-sequence.");
        else
            puts(isAsequence(sequence, D) ? "This is an A-sequence." : "This is not an A-sequence.");
    }
	return 0;
}
