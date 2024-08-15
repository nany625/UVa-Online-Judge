#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(int *array, int size, int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    int t;
    scanf("%d", &t);
    char *buffer = NULL;
    size_t bufsize = 0;
    for(int i = 1; i <= t; ++i) {
        int n;
        scanf("%d", &n);
        int index[n * n + 1];
        memset(index, 0, sizeof(index));
        getline(&buffer, &bufsize, stdin);
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int j = 0;
        while(token) {
            index[atoi(token)] = ++j;
            token = strtok(NULL, " ");
        }
        getline(&buffer, &bufsize, stdin);
        token = strtok(buffer, " ");
        int *lis = NULL, lisSize = 0;
        while(token) {
            int curr = index[atoi(token)], pos = binarySearch(lis, lisSize, curr);
            if(pos == lisSize)
                lis = (int*)realloc(lis, ++lisSize * sizeof(int));
            lis[pos] = curr;
            token = strtok(NULL, " ");
        }
        printf("Case %d: %d\n", i, lisSize);
        free(lis);
    }
    free(buffer);
	return 0;
}
