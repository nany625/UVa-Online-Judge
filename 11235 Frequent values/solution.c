#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(int *array, int size, int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(array[mid] == key)
            return mid;
        if(array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    int n;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%d", &n) && n != 0) {
        int q;
        scanf("%d ", &q);
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int prev = atoi(token), *indices = NULL, size = 0;
        for(int i = 1; i < n; ++i) {
            token = strtok(NULL, " ");
            int curr = atoi(token);
            if(prev != curr) {
                indices = (int*)realloc(indices, (size + 1) * sizeof(int));
                indices[size++] = i;
                prev = curr;
            }
        }
        indices = (int*)realloc(indices, (size + 1) * sizeof(int));
        indices[size++] = n;
        while(q--) {
            int i, j;
            scanf("%d %d", &i, &j);
            int pos = binarySearch(indices, size, i);
            if(indices[pos] >= j)
                printf("%d\n", j - i + 1);
            else {
                int max = indices[pos++] - i + 1;
                while(pos < size && indices[pos] < j) {
                    max = max > indices[pos] - indices[pos - 1] ? max : indices[pos] - indices[pos - 1];
                    ++pos;
                }
                printf("%d\n", max > j - indices[pos - 1] ? max : j - indices[pos - 1]);
            }
        }
        free(indices);
    }
    free(buffer);
	return 0;
}
